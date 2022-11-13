import socket
UDP_IP = "192.168.1.5"
UDP_PORT = 8585
sock = socket.socket(socket.AF_INET, # Internet
                      socket.SOCK_STREAM)
sock.bind((UDP_IP, UDP_PORT))
sock.listen(0)
# sock.sendto(b"MESSAGE", ("192.168.1.12", 8888))
while True:
    data, addr = sock.recvfrom(1024) # buffer size is 1024 bytes
    print("received message: %s" % data)