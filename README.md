# Good UCX test wit log

## Compile

```sh
// anton j2

// using GPU Direct
//server
gcc perftest_hello_server.c -o server -libverbs -lcuda

//client
gcc perftest_hello_client.c -o client -libverbs -lcuda

// CPU using only
//server
g++ -o ucx_perftest_server ucx_perftest_server.cpp -lucp -lucs -luct

//client
g++ -o ucx_perftest_client ucx_perftest_client.cpp -lucp -lucs -luct
```

## Run

```sh
// using GPU Direct
//server
./server

//client
./client

// CPU using only
// server
./ucx_perftest_server

//client
./ucx_perftest_client 10.129.96.9
```

## Output Log

```sh
gehuang@anton-j2:~/ucx-test$ ./ucx_perftest_server
[1726544847.327604] [anton-j2:670206:0]           debug.c:1154 UCX  DEBUG using signal stack 0x7f944ff44000 size 141824
[1726544847.352622] [anton-j2:670206:0]            init.c:120  UCX  DEBUG /usr/local/lib/libucs.so.0 loaded at 0x7f9450540000
[1726544847.352688] [anton-j2:670206:0]            init.c:122  UCX  DEBUG cmd line: ./ucx_perftest_server
[1726544847.352724] [anton-j2:670206:0]          module.c:72   UCX  DEBUG ucs library path: /usr/local/lib/libucs.so.0
[1726544847.352739] [anton-j2:670206:0]          module.c:280  UCX  DEBUG loading modules for ucs
[1726544847.353155] [anton-j2:670206:0]            time.c:22   UCX  DEBUG arch clock frequency: 2200000000.00 Hz
[1726544847.353242] [anton-j2:670206:0]     ucp_context.c:2153 UCX  INFO  Version 1.17.0 (loaded from /usr/local/lib/libucp.so.0)
[1726544847.353260] [anton-j2:670206:0]     ucp_context.c:1919 UCX  DEBUG estimated number of endpoints is 1
[1726544847.353270] [anton-j2:670206:0]     ucp_context.c:1926 UCX  DEBUG estimated number of endpoints per node is 1
[1726544847.353283] [anton-j2:670206:0]     ucp_context.c:1937 UCX  DEBUG estimated bcopy bandwidth is 7340032000.000000
[1726544847.353318] [anton-j2:670206:0]     ucp_context.c:1996 UCX  DEBUG allocation method[0] is md 'sysv'
[1726544847.353327] [anton-j2:670206:0]     ucp_context.c:1996 UCX  DEBUG allocation method[1] is md 'posix'
[1726544847.353344] [anton-j2:670206:0]     ucp_context.c:2008 UCX  DEBUG allocation method[2] is 'thp'
[1726544847.353352] [anton-j2:670206:0]     ucp_context.c:1996 UCX  DEBUG allocation method[3] is md '*'
[1726544847.353361] [anton-j2:670206:0]     ucp_context.c:2008 UCX  DEBUG allocation method[4] is 'mmap'
[1726544847.353369] [anton-j2:670206:0]     ucp_context.c:2008 UCX  DEBUG allocation method[5] is 'heap'
[1726544847.353398] [anton-j2:670206:0]          module.c:280  UCX  DEBUG loading modules for uct
[1726544849.248228] [anton-j2:670206:0]          module.c:280  UCX  DEBUG loading modules for uct_cuda
[1726544849.248484] [anton-j2:670206:0]          module.c:162  UCX  DEBUG ignoring 'ucs_module_global_init' (0x7f944ff33a50) from libuct_cuda.so.0 (0x7f944ff2c000), expected in libuct_cuda_gdrcopy.so.0 (7f94506b4000)
[1726544849.249610] [anton-j2:670206:0]            topo.c:278  UCX  DEBUG added sys_dev 0 for bus id 18:00.0
[1726544849.249643] [anton-j2:670206:0]            topo.c:278  UCX  DEBUG added sys_dev 1 for bus id 3b:00.0
[1726544849.249666] [anton-j2:670206:0]            topo.c:278  UCX  DEBUG added sys_dev 2 for bus id 86:00.0
[1726544849.249688] [anton-j2:670206:0]            topo.c:278  UCX  DEBUG added sys_dev 3 for bus id af:00.0
[1726544849.249719] [anton-j2:670206:0]          module.c:280  UCX  DEBUG loading modules for uct_ib
[1726544849.249959] [anton-j2:670206:0]     ucp_context.c:1574 UCX  DEBUG closing md self because it has no selected transport resources
[1726544849.250609] [anton-j2:670206:0]       tcp_iface.c:926  UCX  DEBUG filtered out bridge device docker0
[1726544849.252402] [anton-j2:670206:0]            topo.c:857  UCX  DEBUG /sys/class/net/eno3: PF sysfs path is '/sys/devices/pci0000:00/0000:00:1c.0/0000:01:00.0'
[1726544849.252454] [anton-j2:670206:0]            topo.c:278  UCX  DEBUG added sys_dev 4 for bus id 01:00.0
[1726544849.252460] [anton-j2:670206:0]            topo.c:522  UCX  DEBUG eno3: bdf_name 0000:01:00.0 sys_dev 4
[1726544849.254890] [anton-j2:670206:0]            topo.c:853  UCX  DEBUG /sys/class/net/lo: sysfs path undetected
[1726544849.254895] [anton-j2:670206:0]            topo.c:526  UCX  DEBUG lo: system device unknown
[1726544849.256301] [anton-j2:670206:0]     ucp_context.c:1574 UCX  DEBUG closing md tcp because it has no selected transport resources
[1726544849.256356] [anton-j2:670206:0]     ucp_context.c:1574 UCX  DEBUG closing md sysv because it has no selected transport resources
[1726544849.256406] [anton-j2:670206:0]     ucp_context.c:1574 UCX  DEBUG closing md posix because it has no selected transport resources
[1726544849.256426] [anton-j2:670206:0]    cuda_copy_md.c:93   UCX  DEBUG dmabuf is not supported on cuda device 0
[1726544849.256450] [anton-j2:670206:0]      cuda_iface.c:51   UCX  DEBUG set cuda sys_device to `unknown` as no context is currently active
[1726544849.256459] [anton-j2:670206:0]     ucp_context.c:1574 UCX  DEBUG closing md cuda_cpy because it has no selected transport resources
[1726544849.256483] [anton-j2:670206:0]      cuda_iface.c:51   UCX  DEBUG set cuda sys_device to `unknown` as no context is currently active
[1726544849.256491] [anton-j2:670206:0]     ucp_context.c:1574 UCX  DEBUG closing md cuda_ipc because it has no selected transport resources
[1726544849.256524] [anton-j2:670206:0]      cuda_iface.c:51   UCX  DEBUG set cuda sys_device to `unknown` as no context is currently active
[1726544849.256533] [anton-j2:670206:0]     ucp_context.c:1574 UCX  DEBUG closing md gdr_copy because it has no selected transport resources
[1726544849.258669] [anton-j2:670206:0]    ib_mlx5dv_md.c:1127 UCX  DEBUG mlx5dv_open_device(mlx5_0) failed: Invalid argument
[1726544849.258675] [anton-j2:670206:0]    ib_mlx5dv_md.c:1799 UCX  DEBUG mlx5_0: DEVX is not supported
[1726544849.258679] [anton-j2:670206:0]           ib_md.c:1076 UCX  DEBUG mlx5_0: md open by 'uct_ib_mlx5_devx_md_ops' failed, trying next
[1726544849.285623] [anton-j2:670206:0]            topo.c:857  UCX  DEBUG /sys/class/infiniband/mlx5_0: PF sysfs path is '/sys/devices/pci0000:5d/0000:5d:00.0/0000:5e:00.0'
[1726544849.285664] [anton-j2:670206:0]            topo.c:278  UCX  DEBUG added sys_dev 5 for bus id 5e:00.0
[1726544849.285669] [anton-j2:670206:0]            topo.c:522  UCX  DEBUG mlx5_0: bdf_name 0000:5e:00.0 sys_dev 5
[1726544849.285686] [anton-j2:670206:0]       ib_device.c:486  UCX  DEBUG mlx5_0: vendor_id 0x15b3 device_id 4115
[1726544849.321478] [anton-j2:670206:0]    ib_mlx5dv_md.c:2414 UCX  DEBUG mlx5_0: DC is supported
[1726544849.321593] [anton-j2:670206:0]           async.c:231  UCX  DEBUG added async handler 0x55e12900c960 [id=29 ref 1] ???() to hash
[1726544849.321772] [anton-j2:670206:0]           async.c:493  UCX  DEBUG listening to async event fd 29 events 0x1 mode thread_spinlock
[1726544849.321790] [anton-j2:670206:0]       ib_device.c:584  UCX  DEBUG initialized device 'mlx5_0' (InfiniBand channel adapter) with 1 ports
[1726544849.321816] [anton-j2:670206:0]           ib_md.c:1130 UCX  DEBUG mlx5_0: cuda GPUDirect RDMA is enabled
[1726544849.321832] [anton-j2:670206:0]           ib_md.c:1130 UCX  DEBUG mlx5_0: rocm GPUDirect RDMA is disabled
[1726544849.321852] [anton-j2:670206:0]           ib_md.c:1151 UCX  DEBUG mlx5_0: ibv_reg_dmabuf_mr(fd=-1) returned Protocol not supported, dmabuf is not supported
[1726544849.321866] [anton-j2:670206:0]           ib_md.c:1119 UCX  DEBUG mlx5_0: relaxed order memory access is disabled
[1726544849.324858] [anton-j2:670206:0]           ib_md.c:1070 UCX  DEBUG mlx5_0: md open by 'uct_ib_mlx5_md_ops' is successful
[1726544849.324971] [anton-j2:670206:0]       ib_device.c:1052 UCX  DEBUG no compatible IB ports found for flags 0xc4
[1726544849.324989] [anton-j2:670206:0]          uct_md.c:96   UCX  DEBUG failed to query dc_mlx5 resources: No such device
[1726544849.326091] [anton-j2:670206:0]       ib_device.c:1052 UCX  DEBUG no compatible IB ports found for flags 0x0
[1726544849.326105] [anton-j2:670206:0]          uct_md.c:96   UCX  DEBUG failed to query rc_verbs resources: No such device
[1726544849.326126] [anton-j2:670206:0]       ib_device.c:1052 UCX  DEBUG no compatible IB ports found for flags 0x4
[1726544849.326135] [anton-j2:670206:0]          uct_md.c:96   UCX  DEBUG failed to query rc_mlx5 resources: No such device
[1726544849.326144] [anton-j2:670206:0]          uct_md.c:96   UCX  DEBUG failed to query gga_mlx5 resources: No such device
[1726544849.326158] [anton-j2:670206:0]       ib_device.c:1052 UCX  DEBUG no compatible IB ports found for flags 0x0
[1726544849.326166] [anton-j2:670206:0]          uct_md.c:96   UCX  DEBUG failed to query ud_verbs resources: No such device
[1726544849.326175] [anton-j2:670206:0]       ib_device.c:1052 UCX  DEBUG no compatible IB ports found for flags 0x4
[1726544849.326184] [anton-j2:670206:0]          uct_md.c:96   UCX  DEBUG failed to query ud_mlx5 resources: No such device
[1726544849.326193] [anton-j2:670206:0]     ucp_context.c:1130 UCX  DEBUG No tl resources found for md mlx5_0
[1726544849.326203] [anton-j2:670206:0]     ucp_context.c:1574 UCX  DEBUG closing md mlx5_0 because it has no selected transport resources
[1726544849.326224] [anton-j2:670206:0]       ib_device.c:605  UCX  DEBUG destroying ib device mlx5_0
[1726544849.326251] [anton-j2:670206:0]           async.c:156  UCX  DEBUG removed async handler 0x55e12900c960 [id=29 ref 1] ???() from hash
[1726544849.326261] [anton-j2:670206:0]           async.c:546  UCX  DEBUG removing async handler 0x55e12900c960 [id=29 ref 1] ???()
[1726544849.326375] [anton-j2:670206:0]           async.c:171  UCX  DEBUG release async handler 0x55e12900c960 [id=29 ref 0] ???()
[1726544849.329083] [anton-j2:670206:0]    ib_mlx5dv_md.c:1127 UCX  DEBUG mlx5dv_open_device(mlx5_1) failed: Invalid argument
[1726544849.329097] [anton-j2:670206:0]    ib_mlx5dv_md.c:1799 UCX  DEBUG mlx5_1: DEVX is not supported
[1726544849.329106] [anton-j2:670206:0]           ib_md.c:1076 UCX  DEBUG mlx5_1: md open by 'uct_ib_mlx5_devx_md_ops' failed, trying next
[1726544849.337711] [anton-j2:670206:0]            topo.c:857  UCX  DEBUG /sys/class/infiniband/mlx5_1: PF sysfs path is '/sys/devices/pci0000:5d/0000:5d:00.0/0000:5e:00.1'
[1726544849.337768] [anton-j2:670206:0]            topo.c:278  UCX  DEBUG added sys_dev 6 for bus id 5e:00.1
[1726544849.337777] [anton-j2:670206:0]            topo.c:522  UCX  DEBUG mlx5_1: bdf_name 0000:5e:00.1 sys_dev 6
[1726544849.337800] [anton-j2:670206:0]       ib_device.c:486  UCX  DEBUG mlx5_1: vendor_id 0x15b3 device_id 4115
[1726544849.384582] [anton-j2:670206:0]    ib_mlx5dv_md.c:2414 UCX  DEBUG mlx5_1: DC is supported
[1726544849.384659] [anton-j2:670206:0]           async.c:231  UCX  DEBUG added async handler 0x55e128fff640 [id=29 ref 1] ???() to hash
[1726544849.384781] [anton-j2:670206:0]           async.c:493  UCX  DEBUG listening to async event fd 29 events 0x1 mode thread_spinlock
[1726544849.384795] [anton-j2:670206:0]       ib_device.c:584  UCX  DEBUG initialized device 'mlx5_1' (InfiniBand channel adapter) with 1 ports
[1726544849.384817] [anton-j2:670206:0]           ib_md.c:1130 UCX  DEBUG mlx5_1: cuda GPUDirect RDMA is enabled
[1726544849.384833] [anton-j2:670206:0]           ib_md.c:1130 UCX  DEBUG mlx5_1: rocm GPUDirect RDMA is disabled
[1726544849.384849] [anton-j2:670206:0]           ib_md.c:1151 UCX  DEBUG mlx5_1: ibv_reg_dmabuf_mr(fd=-1) returned Protocol not supported, dmabuf is not supported
[1726544849.384860] [anton-j2:670206:0]           ib_md.c:1119 UCX  DEBUG mlx5_1: relaxed order memory access is disabled
[1726544849.388005] [anton-j2:670206:0]           ib_md.c:1070 UCX  DEBUG mlx5_1: md open by 'uct_ib_mlx5_md_ops' is successful
[1726544849.389324] [anton-j2:670206:0]          uct_md.c:96   UCX  DEBUG failed to query gga_mlx5 resources: No such device
[1726544849.389549] [anton-j2:670206:0]     ucp_context.c:1574 UCX  DEBUG closing md cma because it has no selected transport resources
[1726544849.389651] [anton-j2:670206:0]     ucp_context.c:1574 UCX  DEBUG closing md knem because it has no selected transport resources
[1726544849.389676] [anton-j2:670206:0]     ucp_context.c:1639 UCX  DEBUG register host memory on: mlx5_1
[1726544849.389686] [anton-j2:670206:0]     ucp_context.c:1639 UCX  DEBUG register cuda memory on: mlx5_1
[1726544849.389696] [anton-j2:670206:0]     ucp_context.c:1627 UCX  DEBUG no memory domain supports registering cuda-managed memory
[1726544849.389705] [anton-j2:670206:0]     ucp_context.c:1627 UCX  DEBUG no memory domain supports registering rocm memory
[1726544849.389716] [anton-j2:670206:0]     ucp_context.c:1627 UCX  DEBUG no memory domain supports registering rocm-managed memory
[1726544849.389725] [anton-j2:670206:0]     ucp_context.c:1627 UCX  DEBUG no memory domain supports registering rdma memory
[1726544849.389786] [anton-j2:670206:0]           mpool.c:136  UCX  DEBUG mpool rcache_mp: align 8, maxelems 4294967295, elemsize 144
[1726544849.389842] [anton-j2:670206:0]           async.c:231  UCX  DEBUG added async handler 0x55e12900cfa0 [id=33 ref 1] ???() to hash
[1726544849.389866] [anton-j2:670206:0]           async.c:493  UCX  DEBUG listening to async event fd 33 events 0x1 mode thread_spinlock
[1726544849.390121] [anton-j2:670206:0]          module.c:280  UCX  DEBUG loading modules for ucm
[1726544849.445536] [anton-j2:670206:0]     ucp_context.c:2225 UCX  DEBUG created ucp context ucp_context_0 0x55e128fde860 [1 mds 4 tls] features 0x1 tl bitmap 0xf 0x0
[1726544849.446123] [anton-j2:670206:0]        ib_iface.c:989  UCX  DEBUG using pkey[0] 0xffff on mlx5_1:1/IB
[1726544849.448048] [anton-j2:670206:0]        ib_iface.c:1567 UCX  DEBUG created uct_ib_iface_t headroom_ofs 12 payload_ofs 92 hdr_ofs 91 data_sz 8256
[1726544849.448144] [anton-j2:670206:0]           mpool.c:136  UCX  DEBUG mpool rc_recv_desc: align 64, maxelems 4294967295, elemsize 8355
[1726544849.448158] [anton-j2:670206:0]           mpool.c:136  UCX  DEBUG mpool rc_send_desc: align 64, maxelems 4294967295, elemsize 8320
[1726544849.448383] [anton-j2:670206:0]           mpool.c:136  UCX  DEBUG mpool send-ops-mpool: align 64, maxelems 4294967295, elemsize 48
[1726544849.449464] [anton-j2:670206:0]           mpool.c:136  UCX  DEBUG mpool pending-ops: align 1, maxelems 4294967295, elemsize 64
[1726544849.449481] [anton-j2:670206:0]           mpool.c:136  UCX  DEBUG mpool rc_verbs_short_desc: align 64, maxelems 4294967295, elemsize 192
[1726544849.450567] [anton-j2:670206:0]        ib_iface.c:1108 UCX  DEBUG iface=0x55e1290cafa0: created RC QP 0x221 on mlx5_1:1 TX wr:409 sge:5 inl:124 resp:64 RX wr:0 sge:0 resp:64
[1726544849.452297] [anton-j2:670206:0]      ucp_worker.c:1425 UCX  DEBUG created interface[0]=0x55e1290cafa0 using rc_verbs/mlx5_1:1 on worker 0x55e1290ab050
[1726544849.452545] [anton-j2:670206:0]        ib_iface.c:989  UCX  DEBUG using pkey[0] 0xffff on mlx5_1:1/IB
[1726544849.452574] [anton-j2:670206:0]       ib_device.c:1263 UCX  DEBUG max IB CQE size is 128
[1726544849.454432] [anton-j2:670206:0]        ib_iface.c:1567 UCX  DEBUG created uct_ib_iface_t headroom_ofs 12 payload_ofs 92 hdr_ofs 90 data_sz 8256
[1726544849.454451] [anton-j2:670206:0]           mpool.c:136  UCX  DEBUG mpool rc_recv_desc: align 64, maxelems 4294967295, elemsize 8354
[1726544849.454455] [anton-j2:670206:0]           mpool.c:136  UCX  DEBUG mpool rc_send_desc: align 64, maxelems 4294967295, elemsize 8320
[1726544849.454498] [anton-j2:670206:0]           mpool.c:136  UCX  DEBUG mpool send-ops-mpool: align 64, maxelems 4294967295, elemsize 48
[1726544849.454869] [anton-j2:670206:0]           mpool.c:136  UCX  DEBUG mpool pending-ops: align 1, maxelems 4294967295, elemsize 64
[1726544849.454882] [anton-j2:670206:0]         ib_mlx5.c:1015 UCX  DEBUG SL=0 (AR support - unknown) was selected on mlx5_1:1, SLs with AR support = { <none> }, SLs without AR support = { <none> }
[1726544849.454892] [anton-j2:670206:0]  rc_mlx5_common.c:722  UCX  DEBUG ibv_alloc_dm(dev=mlx5_1 length=2048) failed: Invalid argument
[1726544849.454897] [anton-j2:670206:0]           mpool.c:136  UCX  DEBUG mpool rc_mlx5_atomic_desc: align 64, maxelems 4294967295, elemsize 72
[1726544849.454912] [anton-j2:670206:0]      ucp_worker.c:1425 UCX  DEBUG created interface[1]=0x55e129195030 using rc_mlx5/mlx5_1:1 on worker 0x55e1290ab050
[1726544849.455025] [anton-j2:670206:0]        ib_iface.c:989  UCX  DEBUG using pkey[0] 0xffff on mlx5_1:1/IB
[1726544849.455756] [anton-j2:670206:0]        ib_iface.c:1567 UCX  DEBUG created uct_ib_iface_t headroom_ofs 12 payload_ofs 92 hdr_ofs 44 data_sz 4136
[1726544849.456223] [anton-j2:670206:0]        ib_iface.c:1108 UCX  DEBUG iface=0x55e12913c4e0: created UD QP 0x223 on mlx5_1:1 TX wr:341 sge:6 inl:124 resp:0 RX wr:4096 sge:1 resp:0
[1726544849.457618] [anton-j2:670206:0]           mpool.c:136  UCX  DEBUG mpool ud_recv_skb: align 64, maxelems 4294967295, elemsize 4188
[1726544849.458189] [anton-j2:670206:0]           mpool.c:281  UCX  DEBUG mpool ud_recv_skb: allocated chunk 0x7f944c1e3018 of 544744 bytes with 128 elements
[1726544849.458197] [anton-j2:670206:0]           mpool.c:136  UCX  DEBUG mpool ud_tx_skb: align 64, maxelems 4294967295, elemsize 4208
[1726544849.458219] [anton-j2:670206:0]        ud_iface.c:380  UCX  DEBUG iface 0x55e12913c4e0: adding gid fe80::506b:4b03:26:9065 to hash on device mlx5_1 port 1 index 0)
[1726544849.458235] [anton-j2:670206:0]        ud_iface.c:380  UCX  DEBUG iface 0x55e12913c4e0: adding gid fe80:: to hash on device mlx5_1 port 1 index 1)
[1726544849.458247] [anton-j2:670206:0]        ud_iface.c:380  UCX  DEBUG iface 0x55e12913c4e0: adding gid fe80:: to hash on device mlx5_1 port 1 index 2)
[1726544849.458261] [anton-j2:670206:0]        ud_iface.c:380  UCX  DEBUG iface 0x55e12913c4e0: adding gid fe80:: to hash on device mlx5_1 port 1 index 3)
[1726544849.458273] [anton-j2:670206:0]        ud_iface.c:380  UCX  DEBUG iface 0x55e12913c4e0: adding gid fe80:: to hash on device mlx5_1 port 1 index 4)
[1726544849.458285] [anton-j2:670206:0]        ud_iface.c:380  UCX  DEBUG iface 0x55e12913c4e0: adding gid fe80:: to hash on device mlx5_1 port 1 index 5)
[1726544849.458297] [anton-j2:670206:0]        ud_iface.c:380  UCX  DEBUG iface 0x55e12913c4e0: adding gid fe80:: to hash on device mlx5_1 port 1 index 6)
[1726544849.458310] [anton-j2:670206:0]        ud_iface.c:380  UCX  DEBUG iface 0x55e12913c4e0: adding gid fe80:: to hash on device mlx5_1 port 1 index 7)
[1726544849.458575] [anton-j2:670206:0]     timer_wheel.c:40   UCX  DEBUG high res timer created log=23 resolution=3813.003636 usec wanted: 2500.000000 usec
[1726544849.458611] [anton-j2:670206:0]           async.c:231  UCX  DEBUG added async handler 0x55e12913cf50 [id=37 ref 1] ???() to hash
[1726544849.458636] [anton-j2:670206:0]           async.c:493  UCX  DEBUG listening to async event fd 37 events 0x5 mode thread_spinlock
[1726544849.458673] [anton-j2:670206:0]      ucp_worker.c:1425 UCX  DEBUG created interface[2]=0x55e12913c4e0 using ud_verbs/mlx5_1:1 on worker 0x55e1290ab050
[1726544849.460481] [anton-j2:670206:0]        ib_iface.c:989  UCX  DEBUG using pkey[0] 0xffff on mlx5_1:1/IB
[1726544849.461839] [anton-j2:670206:0]        ib_iface.c:1567 UCX  DEBUG created uct_ib_iface_t headroom_ofs 12 payload_ofs 92 hdr_ofs 44 data_sz 4136
[1726544849.462427] [anton-j2:670206:0]        ib_iface.c:1108 UCX  DEBUG iface=0x55e128feb120: created UD QP 0x226 on mlx5_1:1 TX wr:256 sge:2 inl:60 resp:0 RX wr:4096 sge:1 resp:0
[1726544849.462458] [anton-j2:670206:0]         ib_mlx5.c:713  UCX  DEBUG tx wq 32768 bytes [bb=64, nwqe=512] mmio_mode bf_post
[1726544849.462747] [anton-j2:670206:0]           mpool.c:136  UCX  DEBUG mpool ud_recv_skb: align 64, maxelems 4294967295, elemsize 4188
[1726544849.463152] [anton-j2:670206:0]           mpool.c:281  UCX  DEBUG mpool ud_recv_skb: allocated chunk 0x7f944c0dc018 of 544744 bytes with 128 elements
[1726544849.463165] [anton-j2:670206:0]           mpool.c:136  UCX  DEBUG mpool ud_tx_skb: align 64, maxelems 4294967295, elemsize 4208
[1726544849.463198] [anton-j2:670206:0]        ud_iface.c:380  UCX  DEBUG iface 0x55e128feb120: adding gid fe80::506b:4b03:26:9065 to hash on device mlx5_1 port 1 index 0)
[1726544849.463221] [anton-j2:670206:0]        ud_iface.c:380  UCX  DEBUG iface 0x55e128feb120: adding gid fe80:: to hash on device mlx5_1 port 1 index 1)
[1726544849.463244] [anton-j2:670206:0]        ud_iface.c:380  UCX  DEBUG iface 0x55e128feb120: adding gid fe80:: to hash on device mlx5_1 port 1 index 2)
[1726544849.463265] [anton-j2:670206:0]        ud_iface.c:380  UCX  DEBUG iface 0x55e128feb120: adding gid fe80:: to hash on device mlx5_1 port 1 index 3)
[1726544849.463287] [anton-j2:670206:0]        ud_iface.c:380  UCX  DEBUG iface 0x55e128feb120: adding gid fe80:: to hash on device mlx5_1 port 1 index 4)
[1726544849.463309] [anton-j2:670206:0]        ud_iface.c:380  UCX  DEBUG iface 0x55e128feb120: adding gid fe80:: to hash on device mlx5_1 port 1 index 5)
[1726544849.463331] [anton-j2:670206:0]        ud_iface.c:380  UCX  DEBUG iface 0x55e128feb120: adding gid fe80:: to hash on device mlx5_1 port 1 index 6)
[1726544849.463352] [anton-j2:670206:0]        ud_iface.c:380  UCX  DEBUG iface 0x55e128feb120: adding gid fe80:: to hash on device mlx5_1 port 1 index 7)
[1726544849.463363] [anton-j2:670206:0]         ib_mlx5.c:1015 UCX  DEBUG SL=0 (AR support - unknown) was selected on mlx5_1:1, SLs with AR support = { <none> }, SLs without AR support = { <none> }
[1726544849.463397] [anton-j2:670206:0]     timer_wheel.c:40   UCX  DEBUG high res timer created log=23 resolution=3813.003636 usec wanted: 2500.000000 usec
[1726544849.463422] [anton-j2:670206:0]           async.c:231  UCX  DEBUG added async handler 0x55e12925da80 [id=38 ref 1] ???() to hash
[1726544849.463440] [anton-j2:670206:0]           async.c:493  UCX  DEBUG listening to async event fd 38 events 0x5 mode thread_spinlock
[1726544849.463466] [anton-j2:670206:0]      ucp_worker.c:1425 UCX  DEBUG created interface[3]=0x55e128feb120 using ud_mlx5/mlx5_1:1 on worker 0x55e1290ab050
[1726544849.463475] [anton-j2:670206:0]      ucp_worker.c:1145 UCX  DEBUG selected scalable tl bitmap: 0xf 0x0 (4 tls)
[1726544849.463509] [anton-j2:670206:0]           async.c:231  UCX  DEBUG added async handler 0x55e1290d3bd0 [id=35 ref 1] ???() to hash
[1726544849.463523] [anton-j2:670206:0]           async.c:493  UCX  DEBUG listening to async event fd 35 events 0x0 mode thread_spinlock
[1726544849.463567] [anton-j2:670206:0]           async.c:231  UCX  DEBUG added async handler 0x55e1290d3c10 [id=36 ref 1] ???() to hash
[1726544849.463580] [anton-j2:670206:0]           async.c:493  UCX  DEBUG listening to async event fd 36 events 0x0 mode thread_spinlock
[1726544849.463853] [anton-j2:670206:0]           async.c:231  UCX  DEBUG added async handler 0x55e1290d3d50 [id=39 ref 1] ???() to hash
[1726544849.463869] [anton-j2:670206:0]           async.c:493  UCX  DEBUG listening to async event fd 39 events 0x1 mode thread_spinlock
[1726544849.463880] [anton-j2:670206:0]       rdmacm_cm.c:981  UCX  DEBUG created rdmacm_cm 0x55e128fe98f0 with event_channel 0x55e128fe9ff0 (fd=39)
[1726544849.463905] [anton-j2:670206:0]      tcp_sockcm.c:225  UCX  DEBUG created tcp_sockcm 0x55e129276490
[1726544849.463927] [anton-j2:670206:0]           mpool.c:136  UCX  DEBUG mpool ucp_requests: align 64, maxelems 4294967295, elemsize 272
[1726544849.463935] [anton-j2:670206:0]           mpool.c:136  UCX  DEBUG mpool ucp_rkeys: align 64, maxelems 4294967295, elemsize 104
[1726544849.463955] [anton-j2:670206:0]           mpool.c:136  UCX  DEBUG mpool ucp_reg_bufs: align 64, maxelems 4294967295, elemsize 8216
[1726544849.463965] [anton-j2:670206:0]           mpool.c:136  UCX  DEBUG mpool ucp_am_bufs: align 64, maxelems 4294967295, elemsize 153
[1726544849.463973] [anton-j2:670206:0]           mpool.c:136  UCX  DEBUG mpool ucp_am_bufs: align 64, maxelems 4294967295, elemsize 1113
[1726544849.463981] [anton-j2:670206:0]           mpool.c:136  UCX  DEBUG mpool ucp_am_bufs: align 64, maxelems 4294967295, elemsize 8344
[1726544849.463990] [anton-j2:670206:0]       mpool_set.c:129  UCX  DEBUG mpool_set:ucp_am_bufs, sizes map 0x80000440, largest size 8255, mpools num 3
[1726544849.464059] [anton-j2:670206:0]          parser.c:2243 UCX  INFO  UCX_* env variables: UCX_LOG_LEVEL=debug UCX_TLS=rc UCX_NET_DEVICES=mlx5_1:1
Failed to bind server socket
[1726544849.464392] [anton-j2:670206:0]           async.c:679  UCX  DIAG  async handler table is not empty during exit (contains 7 elems)
[1726544849.464408] [anton-j2:670206:0]          thread.c:433  UCX  DIAG  async thread still running (use count 7)
[1726544849.464416] [anton-j2:670206:0]          thread.c:433  UCX  DIAG  async thread still running (use count 7)
```
