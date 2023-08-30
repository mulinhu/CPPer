1. 安装protobuf: sudo apt install  libprotobuf-dev
2. 运行 protoc --cpp_out=. rpc.proto
3. g++ main.cpp rpc.pb.cc -o main -lprotobuf