# Socket Programming Project

## GitHub Repository

[View the project on GitHub](https://github.com/Maayan500/sockets-final.git)

This project demonstrates socket communication using:
- UDP in Python
- UDP in C++
- TCP in Python
- TCP in C++

The project includes client-server communication examples and execution screenshots.

## Running the Project

### Python

Run server first:

```bash
py 3_tcp_s.py
```

Then run client:

```bash
py 3_tcp_c.py
```

### C++

Using Docker:

```bash
docker run --rm -it -v ${PWD}:/work -w /work gcc bash
```

Compile:

```bash
g++ 4_tcp_s.cpp -o tcp_server
g++ 4_tcp_c.cpp -o tcp_client
```

Run:

```bash
./tcp_server &
./tcp_client
```

# Sockets Exercise

## Part 1 - UDP Communication in Python

In this part of the exercise, UDP communication between a client and a server was implemented using Python sockets.

The server listens on port 12345 and waits for messages from clients.

The client sends the message "Hello" to the server using the localhost IP address 127.0.0.1.

After receiving the message, the server sends the same message back in uppercase letters.

The client receives the response from the server and prints it to the screen.

### Client Code Explanation
`socket(AF_INET, SOCK_DGRAM)` creates a UDP socket using IPv4 communication.

`sendto()` sends data to the server.

`recvfrom()` receives data from the server.

`decode('utf-8')` converts bytes into readable text.

### Server Code Explanation
`bind()` connects the server socket to port 12345.

`recvfrom()` waits for data from clients.

`sendto()` sends the response back to the client.

`while True` keeps the server running continuously.

### Changes Made

Several improvements were added to the original UDP Python client-server code.

1. The communication port was changed from `12345` to `5000`.

2. The client message was changed from:
`Hello`
to:
`Hello from client`

3. The server response was modified to include:
`SERVER RESPONSE:`

before the returned message.

4. A timestamp was added to display the exact time each message was received.

5. A message counter was added to count how many messages were received by the server.

6. Additional status messages were added, such as:
`UDP server is running and waiting for messages...`
and
`Closing client socket...`

These changes improved readability, debugging, and user interaction.

## Part 2 - UDP Communication in C++

In this part of the exercise, UDP communication was implemented using C++ sockets.

The server waits for incoming UDP messages on port 5555.

The client sends the message "hello" to the server using the localhost IP address 127.0.0.1.

After receiving the message, the server prints the received message and sends it back to the client.

The client receives the response from the server and prints it to the screen.

### Code Explanation
`socket(AF_INET, SOCK_DGRAM, 0)` creates a UDP socket.

`bind()` attaches the socket to port 5555.

`recvfrom()` receives data from the client.

`sendto()` sends the response back to the client.

`close()` closes the socket connection.

### Changes Made in UDP C++

Several improvements were added to the original UDP C++ implementation.

1. The communication port was changed from `5555` to `6000`.

2. The client message was changed from:
`hello`
to:
`Hello from C++ client`

3. The server response was modified to include:
`SERVER RESPONSE:`

before the returned message.

4. A startup message was added:
`UDP C++ server is running...`

5. A message counter was added to count received messages.

6. A timestamp was added to display the exact time the server received the message.

These changes improved readability, debugging, and overall user interaction.

## Part 3 - TCP Communication in Python

In this part of the exercise, TCP communication was implemented using Python sockets.

The server listens for incoming TCP connections on port 12345.

The client connects to the server using the localhost IP address `127.0.0.1`.

After the connection is established, the client can send multiple messages to the server.

The server receives the messages, prints them, converts them to uppercase letters, and sends them back to the client.

The connection remains active until the client sends `quit`.

### Code Explanation

`socket.AF_INET` is used for IPv4 communication.

`socket.SOCK_STREAM` creates a TCP socket.

`bind()` connects the server socket to a specific port.

`listen()` makes the server wait for incoming client connections.

`accept()` accepts a client connection and creates a new socket for communication.

`recv()` receives data from the client.

`send()` sends data back to the client.

`connect()` is used by the client to establish a connection with the server.

`close()` closes the socket connection.

### Improvements Added

- Added server startup message
- Added connection status message
- Added message counter
- Added timestamps for received messages
- Added custom server response format
- Added client closing message

## Part 4 - TCP Communication in C++

In this part of the exercise, TCP communication was implemented using C++ sockets.

The server listens for incoming TCP client connections on port 5555.

The client connects to the server using the localhost IP address `127.0.0.1`.

After the connection is established, the client sends a message to the server.

The server receives the message and sends the same message back to the client.

### Code Explanation

`SOCK_STREAM` creates a TCP socket.

`socket()` creates the socket descriptor.

`bind()` attaches the socket to a port.

`listen()` makes the server wait for incoming client connections.

`accept()` accepts a client connection.

`connect()` is used by the client to connect to the server.

`send()` sends data through the TCP connection.

`recv()` receives data from the TCP connection.

`close()` closes the socket connection.

### Improvements Added

- Added server startup message
- Added client connection message
- Added message counter
- Added timestamps for received messages
- Added custom server response format
- Added client closing message
- Changed communication port to 8000