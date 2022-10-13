# Getting started with grpc 

# Install grpc package 

Follow the instruction on https://grpc.io/docs/languages/cpp/quickstart/ to install c++ grpc package on linux machine

Follow the instruction on https://grpc.io/docs/languages/python/quickstart/ to install python packages on linux machine

# Clone the repository

```
git clone https://github.com/gauravratnakar256/grpc-example.git && cd grpc-example
```

# Run server

### 1] Create executable from c++ code

```
cd Server
cmake -DCMAKE_PREFIX_PATH=$MY_INSTALL_DIR
make -j
```

### 2] Run executable

```
./server.exe
```

# Run client

```
cd Client
python client.py
```





