from socket import *

# 포트와 소켓 생성

## serverSocket = socket(AF_INET, SOCK_STREAM)
### AF_INIT -> IPv4 주소 체계 사용
### SOCK_STREAM -> TCP 소켓

## serverSocket.bind((IP주소, 포트번호))
### UDP 서버 소켓을 특정 포트에 바인딩(bind) 하는 역할
### IP주소 -> 특정 IP주소만 들어올 수 있도록 허용
### '' -> 모든 IP주소 들어올 수 있도록 허용

## serverSocket.listen(1)
### TCP 소켓이 클라이언트의 연결 요청을 받을 준비

serverPort = 12000
serverSocket = socket(AF_INET, SOCK_STREAM)
serverSocket.bind( ('', serverPort) )
serverSocket.listen(1)
print('The server is ready to receive')

# message를 받고 대문자로 변환 후 다시 보낸다.
## serverSocket.recvfrom(i)
### 최대 i바이트까지 데이터를 받을 수 있도록 설정 

while 1:
    connectionSocket, address = serverSocket.accept()
    message = connectionSocket.recv(1024)
    connectionSocket.send(message.upper())
    connectionSocket.close() 