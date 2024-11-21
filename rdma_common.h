// rdma_common.h
#ifndef RDMA_COMMON_H
#define RDMA_COMMON_H

#include <infiniband/verbs.h>
#include <cuda_runtime.h>
#include <stdio.h>
#include <stdlib.h>

struct rdma_resource {
    struct ibv_context *context;
    struct ibv_pd *pd;
    struct ibv_mr *mr;
    struct ibv_cq *cq;
    struct ibv_qp *qp;
    cudaStream_t stream;
    char *cuda_buffer;
    size_t buffer_size;
};

// Initialize RDMA and CUDA resources
void init_rdma_resources(struct rdma_resource *res, size_t buffer_size) {
    struct ibv_device **dev_list = ibv_get_device_list(NULL);
    if (!dev_list) {
        perror("Failed to get RDMA devices list");
        exit(1);
    }

    res->context = ibv_open_device(dev_list[0]);
    if (!res->context) {
        perror("Failed to open RDMA device");
        exit(1);
    }

    res->pd = ibv_alloc_pd(res->context);
    if (!res->pd) {
        perror("Failed to allocate protection domain");
        exit(1);
    }

    // Allocate GPU memory
    cudaMalloc((void **)&res->cuda_buffer, buffer_size);
    cudaMemset(res->cuda_buffer, 0, buffer_size);
    res->buffer_size = buffer_size;

    res->mr = ibv_reg_mr(res->pd, res->cuda_buffer, buffer_size, IBV_ACCESS_LOCAL_WRITE |
                         IBV_ACCESS_REMOTE_WRITE | IBV_ACCESS_REMOTE_READ);
    if (!res->mr) {
        perror("Failed to register memory region");
        exit(1);
    }

    // Create CQ and QP
    res->cq = ibv_create_cq(res->context, 10, NULL, NULL, 0);
    if (!res->cq) {
        perror("Failed to create Completion Queue (CQ)");
        exit(1);
    }

    struct ibv_qp_init_attr qp_attr = {
        .send_cq = res->cq,
        .recv_cq = res->cq,
        .qp_type = IBV_QPT_RC,
        .cap = {
            .max_send_wr = 10,
            .max_recv_wr = 10,
            .max_send_sge = 1,
            .max_recv_sge = 1,
        },
    };
    res->qp = ibv_create_qp(res->pd, &qp_attr);

    if (!res->qp) {
        perror("Failed to create Queue Pair");
        exit(1);
    }
}

// Clean up RDMA and CUDA resources
void cleanup_rdma_resources(struct rdma_resource *res) {
    cudaFree(res->cuda_buffer);
    ibv_destroy_qp(res->qp);
    ibv_destroy_cq(res->cq);
    ibv_dereg_mr(res->mr);
    ibv_dealloc_pd(res->pd);
    ibv_close_device(res->context);
}

#endif