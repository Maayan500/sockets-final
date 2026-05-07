#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <ctime>

using namespace std;

int main() {

    const int server_port = 6000;

    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }

    struct sockaddr_in sin;

    memset(&sin, 0, sizeof(sin));

    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);

    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error binding to socket");
    }

    cout << "UDP C++ server is running..." << endl;
    struct sockaddr_in from;
    unsigned int from_len = sizeof(struct sockaddr_in);
    char buffer[4096];
    int message_count = 0;
    int bytes = recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr *) &from, &from_len);
    buffer[bytes] = '\0';
    if (bytes < 0) {
        perror("error reading from socket");
    }
    message_count++;
    cout << "Message number: " << message_count << endl;
    cout << "The client sent: " << buffer << endl;
    time_t now = time(0);
    char* dt = ctime(&now);
    cout << "[" << dt << "] ";
    char response[4096] = "SERVER RESPONSE: ";
    strcat(response, buffer);

    int sent_bytes = sendto(sock, response, strlen(response) + 1, 0,
    (struct sockaddr *) &from, sizeof(from));    
  
    if (sent_bytes < 0) {
        perror("error writing to socket");
    }

    close(sock);

    return 0;
}