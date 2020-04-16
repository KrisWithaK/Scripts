import socket

serverSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
serversocket.bind((socket.gethostname(), 1337))
serversocket.listen(5)

(client,(ip,port))=serverSocket.accept()






#while True:
#    (clientsocket, address) = serversocket.accept()
#    ct = client_thread(clientsocket)
#    ct.run()
