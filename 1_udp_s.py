from socket import socket, AF_INET, SOCK_DGRAM
from datetime import datetime

s = socket(AF_INET, SOCK_DGRAM)

src_ip = ''
src_port = 5000
s.bind((src_ip, src_port))
print("UDP server is running and waiting for messages...")
message_count = 0

while True:
    data, sender_info = s.recvfrom(2048)
    current_time = datetime.now().strftime("%H:%M:%S")
    print(f"[{current_time}] Message received from client:")
    print(data.decode('utf-8'))
    print(sender_info)    
    response = b"SERVER RESPONSE: " + data.upper()
    s.sendto(response, sender_info)

    message_count += 1
    print(f"Message number: {message_count}")