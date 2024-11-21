# GPU Direct RDMA perftest in server - client mode

## Compile

```sh
# anton j2

# using GPU Direct
# server on j6
gcc rdma_server.c -o server -libverbs -lcudart -L/usr/local/cuda/lib64 -I/usr/local/cuda/include

#client on j2
gcc rdma_client.c -o client -libverbs -lcudart -L/usr/local/cuda/lib64 -I/usr/local/cuda/include
```

## Run

```sh
# using GPU Direct
#server
./server

#client
./client
```

## Output Log

```sh
gehuang@anton-j2:~/gpudirect-hello$ ./client
Connected to server.
Message sent to server.

gehuang@anton-j6:~/gpudirect-hello$ ./server
Initializing RDMA resources...
Starting the server...
Server listening on port 12345...
Accepted connfd: 39
Client connected.
Cleaning up RDMA resources...
```
