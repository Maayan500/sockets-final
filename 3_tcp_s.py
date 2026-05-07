import socket
from datetime import datetime

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_ip = ''
server_port = 7000
server.bind((server_ip, server_port))
server.listen(5)
print("TCP Python server is running and waiting for clients...")

while True:
    client_socket, client_address = server.accept()
    print('Connection from: ', client_address)
    message_count = 0
    data = client_socket.recv(1024)
    while not data.decode('utf-8') == '':
        message_count += 1
        print("Message number:", message_count)
        current_time = datetime.now().strftime("%H:%M:%S")
        print(f"[{current_time}] Message received from client:")
        print('Received: ', data.decode('utf-8'))
        response = b"SERVER RESPONSE: " + data.upper()
        client_socket.send(response)
        data = client_socket.recv(1024)

    print('Client disconnected')
    client_socket.close()