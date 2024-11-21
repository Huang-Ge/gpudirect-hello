// rdma_server.c
#include "rdma_common.h"
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

#define PORT 12345
#define BUFFER_SIZE 1024

void run_server(struct rdma_resource *res) {
    int sockfd, connfd;
    struct sockaddr_in server_addr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    // Bind the socket
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Socket bind failed");
        close(sockfd);
        exit(1);
    }

    // Start listening
    if (listen(sockfd, 5) < 0) {
        perror("Socket listen failed");
        close(sockfd);
        exit(1);
    }

    printf("Server listening on port %d...\n", PORT);

    // Accept a client connection
    connfd = accept(sockfd, NULL, NULL);
    printf("Accepted connfd: %d\n", connfd);
    if (connfd < 0) {
        perror("Failed to accept connection");
        close(sockfd);
        exit(1);
    }
    printf("Client connected.\n");

    // Close sockets when done
    close(connfd);
    close(sockfd);
}


int main() {
    struct rdma_resource res;  // Declare the RDMA resource

    // Initialize RDMA resources
    printf("Initializing RDMA resources...\n");
    init_rdma_resources(&res, BUFFER_SIZE);  // Initialize the RDMA resources

    // Run the server
    printf("Starting the server...\n");
    run_server(&res);  // Pass the RDMA resource to the server function

    // Cleanup RDMA resources
    printf("Cleaning up RDMA resources...\n");
    cleanup_rdma_resources(&res);

    return 0;
}