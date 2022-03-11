// HOST

import socket
import time
while True:
sock = socket.socket()
sock.bind(('', 1010))
sock.listen(1)
conn, addr = sock.accept()

print('connected:', addr)

time.sleep(1)
while True:
data = conn.recv(1024)
if not data :
    break
    conn.send(data.upper())
    conn.close()

    // CLIENT

    import socket
    while True:
sock = socket.socket()
sock.connect(('localhost', 1010))
str1 = input()
sock.sendto(str1.encode(), ('localhost', 1010))
data = sock.recv(1024)
sock.close()

print(data)