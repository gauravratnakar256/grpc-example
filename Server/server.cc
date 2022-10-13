#include <grpcpp/grpcpp.h>
#include <string>
#include "greet.grpc.pb.h"


using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

using greet::GreetService;
using greet::GreetRequest;
using greet::GreetResponse;


class GreetServiceImpl final : public GreetService::Service {
    Status Greet(
        ServerContext* context, 
        const GreetRequest* request, 
        GreetResponse* reply
    ) override {
        
        reply->set_result("Hello " + request->first_name());

        return Status::OK;
    } 
};

void Run() {
    std::string address("0.0.0.0:50051");
    GreetServiceImpl service;

    ServerBuilder builder;

    builder.AddListeningPort(address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on port: " << address << std::endl;

    server->Wait();
}

int main(int argc, char** argv) {
    Run();

    return 0;
}