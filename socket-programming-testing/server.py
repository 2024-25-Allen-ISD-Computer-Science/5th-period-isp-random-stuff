import socket
import threading

HEADER = 64
PORT = 8000
#SERVER = socket.gethostbyname(socket.gethostname())
SERVER = "0.0.0.0"
ADDR = (SERVER, PORT)
FORMAT = "utf-8"
DC_MSG = "!DC"

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(ADDR)
def handle_client(conn, addr):
    print(f"NEW CONNECTION: {addr} connected")
    connected = True
    while connected:
        msg_length = (conn.recv(HEADER).decode(FORMAT))
        if msg_length:
            msg_length = int(msg_length)
            msg = conn.recv(msg_length).decode(FORMAT)
            if msg == DC_MSG:
                connected = False
            print(f"addr = {addr}, message = {msg}")
            conn.send("msg recvd".encode(FORMAT))

    conn.close()


def start():
    server.listen()
    while(True):
        conn, addr = server.accept()
        thread = threading.Thread(target=handle_client, args=(conn, addr))
        thread.start()
        print(f"CONNECTIONS: {threading.active_count()-1}")

print("server starting")
start()
