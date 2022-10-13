import greet_pb2_grpc as pb2_grpc
import greet_pb2 as pb2
import grpc

class GreetClient:

    def __init__(self):
        self.host = 'localhost'
        self.server_port = 50051

        self.channel = grpc.insecure_channel('localhost:50051')
        self.stub = pb2_grpc.GreetServiceStub(self.channel)

    def getGreetResponse(self, message):
        message = pb2.GreetRequest(first_name = message)
        print(f'{message}')
        return self.stub.Greet(message)

if __name__ == '__main__':
    client = GreetClient()
    result = client.getGreetResponse(message="Gaurav")
    print(f'{result}')