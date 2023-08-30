#include <iostream>
#include <string>
#include "rpc.pb.h"

using namespace std;
using rpc::AddRequest;
using rpc::AddResponse;

int main() {

    // 构建请求消息
    AddRequest request;
    request.set_x(5);
    request.set_y(3);
    
    // 将消息进行序列化成字符串存储至requestStr
    string requestStr;
    request.SerializeToString(&requestStr);
  
    //对字符串进行解析
    AddRequest req;
    req.ParseFromString(requestStr);
    
    AddResponse response;
    response.set_result(request.x() + request.y());
    cout<<"result:"<<response.result()<<endl;
    
  return 0;
}