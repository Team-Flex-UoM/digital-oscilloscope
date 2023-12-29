import socket
UDP_IP = "192.168.43.89"
UDP_PORT = 52432
sock = socket.socket(socket.AF_INET, # Internet
                      socket.SOCK_DGRAM) # UDP
sock.bind((UDP_IP, UDP_PORT))
sock.sendto(b"MESSAGE", ("192.168.43.94", 4210))
while True:
    data, addr = sock.recvfrom(1024) # buffer size is 1024 bytes
    print("received message: %s" % data)