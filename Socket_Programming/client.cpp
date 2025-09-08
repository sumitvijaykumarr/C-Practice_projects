#include"iostream"
#include"cstring"
#include"sys/socket.h"
#include"arpa/inet.h"
#include"unistd.h"

#define PORT 8080

int main(){
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};

    if((sock = socket(AF_INET, SOCK_STREAM, 0))< 0 ){
        std::cerr<<"Socket Creation Error"<<std::endl;
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0){
        std::cerr<<"Invalid address / Address not supported"<<std::endl;
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
        std::cerr<<"Connection Failed"<<std::endl;
        return -1;
    }

    std::string message;
    while(true){
        std::cout<<"nter message for server (type 'exit' to quit): ";
        std::getline(std::cin, message);
        if (message == "exit") break;

        send(sock, message.c_str(), message.size(), 0);

        memset(buffer, 0, 1024);
        read(sock, buffer, 1024);
        std::cout<<"Server: "<<buffer<<std::endl;

    }
    close(sock);
    return 0;
}