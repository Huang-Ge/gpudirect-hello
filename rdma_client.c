// rdma_client.c
#include "rdma_common.h"
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define SERVER_IP "10.129.96.13"
#define PORT 12345
#define BUFFER_SIZE 1024

void run_client() {
    struct rdma_resource res;
    init_rdma_resources(&res, BUFFER_SIZE);

    // Create socket and connect
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr = {.sin_family = AF_INET, .sin_port = htons(PORT)};
    inet_pton(AF_INET, SERVER_IP, &addr.sin_addr);
    connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));

    printf("Connected to server.\n");

    // Write data into GPU buffer
    const char *message = "Hello from client via RDMA!";
    cudaMemcpy(res.cuda_buffer, message, strlen(message) + 1, cudaMemcpyHostToDevice);

    // Send data to server
    struct ibv_sge sge = {
        .addr   = (uintptr_t)res.cuda_buffer,
        .length = BUFFER_SIZE,
        .lkey   = res.mr->lkey,
    };

    struct ibv_send_wr wr = {
        .wr_id      = 0,
        .sg_list    = &sge,
        .num_sge    = 1,
        .opcode     = IBV_WR_SEND,
        .send_flags = IBV_SEND_SIGNALED,
    };

    struct ibv_send_wr *bad_wr;
    if (ibv_post_send(res.qp, &wr, &bad_wr)) {
        perror("ibv_post_send failed");
        exit(1);
    }

    printf("Message sent to server.\n");

    cleanup_rdma_resources(&res);
    close(sockfd);
}

int main() {
    run_client();
    return 0;
}