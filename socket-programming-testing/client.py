import socket 

HEADER = 64
PORT = 8000
SERVER = "172.17.0.16"
FORMAT = "utf-8"
DC_MSG = "!DC"
ADDR = (SERVER, PORT)

last_msg = ""
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect(ADDR)

def send(msg):
    message = msg.encode(FORMAT)
    msg_length = len(message)
    send_length = str(msg_length).encode(FORMAT)
    send_length += b' ' * (HEADER - len(send_length))
    client.send(send_length)
    client.send(message)
    print(client.recv(2048).decode(FORMAT))
while True:
    send(input("message: "))
#    if (client.recv(2048) != last_msg):
#        print(client.recv(2048))
#        last_msg = client.recv(2048)
