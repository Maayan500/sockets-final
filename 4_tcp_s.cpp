#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <ctime>
#include <string>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

using namespace std;

int main() {

    const int server_port = 8000;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }

    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);

    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error binding socket");
    }

    if (listen(sock, 5) < 0) {
        perror("error listening to a socket");
    }
    cout << "TCP C++ server is running and waiting for clients..." << endl;

    struct sockaddr_in client_sin;
    unsigned int addr_len = sizeof(client_sin);
    int client_sock = accept(sock,  (struct sockaddr *) &client_sin,  &addr_len);

    if (client_sock < 0) {
        perror("error accepting client");
    }
    cout << "Client connected to TCP C++ server." << endl;
    int message_count = 0;

    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(client_sock, buffer, expected_data_len, 0);
    buffer[read_bytes] = '\0';
    if (read_bytes == 0) {
    // connection is closed
    }
    else if (read_bytes < 0) {
    // error
    }
    else {
    message_count++;

    time_t now = time(0);
    char* dt = ctime(&now);

    cout << "Message number: " << message_count << endl;
    cout << "[" << dt << "] ";
    cout << "The client sent: " << buffer << endl;
    }

string response = "SERVER RESPONSE: ";
response += buffer;
int sent_bytes = send(client_sock, response.c_str(), response.length(), 0);
if (sent_bytes < 0) {
        perror("error sending to client");
    }

    close(client_sock);
    close(sock);


    return 0;
}