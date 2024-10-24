#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <infiniband/verbs.h>
#include <cuda.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define SERVER_IP "10.129.96.9"
#define PORT 12345
#define BUFFER_SIZE 4096

struct rdma_resource {
    struct ibv_context *context;
    struct ibv_pd *pd;
    struct ibv_mr *mr;
    struct ibv_cq *cq;
    struct ibv_qp *qp;
    CUdeviceptr cuda_buffer;
};

int init_gpu(struct rdma_resource *res) {
    CUresult error = cuInit(0);
    if (error != CUDA_SUCCESS) {
        printf("CUDA initialization failed, error: %d\n", error);
        return -1;
    }

    CUdevice device;
    cuDeviceGet(&device, 0);
    CUcontext cuda_context;
    cuCtxCreate(&cuda_context, 0, device);

    printf("CUDA device initialized\n");

    cuMemAlloc(&res->cuda_buffer, BUFFER_SIZE);
    if (!res->cuda_buffer) {
        printf("CUDA memory allocation failed\n");
        return -1;
    }

    printf("Allocated CUDA memory: %p\n", (void *)res->cuda_buffer);
    return 0;
}

void create_rdma_resources(struct rdma_resource *res, const char* devname) {
    struct ibv_device **dev_list;
    int num_devices;

    dev_list = ibv_get_device_list(&num_devices);
    if (!dev_list || num_devices == 0) {
        perror("No RDMA devices found");
        exit(1);
    }

    struct ibv_device *ib_dev = NULL;
    for (int i = 0; i < num_devices; i++) {
        if (strcmp(ibv_get_device_name(dev_list[i]), devname) == 0) {
            ib_dev = dev_list[i];
            break;
        }
    }

    if (!ib_dev) {
        fprintf(stderr, "Device %s not found\n", devname);
        exit(1);
    }

    res->context = ibv_open_device(ib_dev);
    if (!res->context) {
        perror("Failed to open device context");
        exit(1);
    }

    res->pd = ibv_alloc_pd(res->context);
    if (!res->pd) {
        perror("Failed to allocate protection domain");
        exit(1);
    }

    if (init_gpu(res) < 0) {
        fprintf(stderr, "Failed to initialize GPU memory\n");
        exit(1);
    }

    // Register CUDA memory with RDMA
    res->mr = ibv_reg_mr(res->pd, (void *)res->cuda_buffer, BUFFER_SIZE,
                         IBV_ACCESS_LOCAL_WRITE | IBV_ACCESS_REMOTE_WRITE);
    if (!res->mr) {
        perror("Failed to register memory region");
        exit(1);
    }

    // Create completion queue (CQ)
    res->cq = ibv_create_cq(res->context, 10, NULL, NULL, 0);
    if (!res->cq) {
        perror("Failed to create CQ");
        exit(1);
    }

    // Create Queue Pair (QP)
    struct ibv_qp_init_attr qp_init_attr = {};
    qp_init_attr.send_cq = res->cq;
    qp_init_attr.recv_cq = res->cq;
    qp_init_attr.cap.max_send_wr = 10;
    qp_init_attr.cap.max_recv_wr = 10;
    qp_init_attr.cap.max_send_sge = 1;
    qp_init_attr.cap.max_recv_sge = 1;
    qp_init_attr.qp_type = IBV_QPT_RC;

    res->qp = ibv_create_qp(res->pd, &qp_init_attr);
    if (!res->qp) {
        perror("Failed to create QP");
        exit(1);
    }

    // Modify QP to INIT state
    struct ibv_qp_attr attr = {};
    attr.qp_state = IBV_QPS_INIT;
    attr.pkey_index = 0;
    attr.port_num = 1;
    attr.qp_access_flags = IBV_ACCESS_REMOTE_READ | IBV_ACCESS_REMOTE_WRITE;

    if (ibv_modify_qp(res->qp, &attr, IBV_QP_STATE | IBV_QP_PKEY_INDEX | IBV_QP_PORT | IBV_QP_ACCESS_FLAGS)) {
        perror("Failed to modify QP to INIT");
        exit(1);
    }

    printf("RDMA resources initialized on device %s\n", devname);
}

void run_client(struct rdma_resource *res) {
    struct sockaddr_in addr;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER_IP, &addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Failed to connect to server");
        exit(1);
    }

    printf("Connected to server at %s:%d\n", SERVER_IP, PORT);

    // Exchanging QP information (for simplicity, just print local QP details)
    struct ibv_port_attr port_attr;
    ibv_query_port(res->context, 1, &port_attr);

    uint32_t local_qpn = res->qp->qp_num;
    uint16_t local_lid = port_attr.lid;

    printf("Local QPN: %u, Local LID: %u\n", local_qpn, local_lid);

    // Write some data into the CUDA buffer
    char data[] = "Hello from client via RDMA!";
    cuMemcpyHtoD(res->cuda_buffer, data, strlen(data) + 1);

    // Send the message to the server using the RDMA buffer
    send(sockfd, (void *)res->cuda_buffer, BUFFER_SIZE, 0);
    printf("Sent message to server (from GPU memory): %s\n", data);

    // Cleanup
    cuMemFree(res->cuda_buffer);
    close(sockfd);
    ibv_destroy_qp(res->qp);
    ibv_destroy_cq(res->cq);
    ibv_dereg_mr(res->mr);
    ibv_dealloc_pd(res->pd);
    ibv_close_device(res->context);
}

int main(int argc, char **argv) {
    struct rdma_resource res;
    create_rdma_resources(&res, "mlx5_1");  // Specify the RDMA device (mlx5_1)
    run_client(&res);
    return 0;
}