from socket import socket, AF_INET, SOCK_DGRAM

s = socket(AF_INET, SOCK_DGRAM)

dst_ip = '127.0.0.1'
dst_port = 5000

s.sendto(b'Hello from client', (dst_ip,dst_port))

data, sender_info = s.recvfrom(2048)
print(data.decode('utf-8'))
print(sender_info)

print("Closing client socket...")
s.close()
