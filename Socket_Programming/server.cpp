// server.cpp - Multi-client support using select()
#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <vector>
#include <algorithm>

#define PORT 8080
#define MAX_CLIENTS 30

int main() {
    int server_fd, new_socket, max_sd;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024];

    fd_set readfds;
    std::vector<int> client_sockets;

    // Create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    std::cout << "Server listening on port " << PORT << std::endl;

    while (true) {
        FD_ZERO(&readfds);
        FD_SET(server_fd, &readfds);
        max_sd = server_fd;

        for (int sd : client_sockets) {
            FD_SET(sd, &readfds);
            max_sd = std::max(max_sd, sd);
        }

        // Wait for an activity on sockets
        int activity = select(max_sd + 1, &readfds, NULL, NULL, NULL);

        if (activity < 0) {
            perror("select error");
            exit(EXIT_FAILURE);
        }

        // Check for new connection
        if (FD_ISSET(server_fd, &readfds)) {
            if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
                perror("accept failed");
                exit(EXIT_FAILURE);
            }
            std::cout << "New client connected. Socket: " << new_socket << std::endl;
            client_sockets.push_back(new_socket);
        }

        // Check for data from clients
        for (auto it = client_sockets.begin(); it != client_sockets.end();) {
            int sd = *it;
            if (FD_ISSET(sd, &readfds)) {
                memset(buffer, 0, 1024);
                int valread = read(sd, buffer, 1024);
                if (valread == 0) {
                    std::cout << "Client disconnected. Socket: " << sd << std::endl;
                    close(sd);
                    it = client_sockets.erase(it);
                    continue;
                }
                std::cout << "Message from client: " << buffer << std::endl;
                std::string response = "Message received!";
                send(sd, response.c_str(), response.size(), 0);
            }
            ++it;
        }
    }

    close(server_fd);
    return 0;
}


// client.cpp remains unchanged
