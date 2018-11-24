import socket
import sys
import json

HOST = ''  # Standard loopback interface address (localhost)
PORT = 30025        # Port to listen on (non-privileged ports are > 1023)

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST, PORT))
    s.listen()
    conn, addr = s.accept()
    data = conn.recv(1024)

data = data.decode("utf-8")
data = json.loads(data)
print(data)
print(data['test'])

