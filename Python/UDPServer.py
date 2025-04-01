from socket import *

# 포트와 소켓 생성
## AF_INIT -> IPv4 주소 체계 사용
## SOCK_DGRAM -> UDP 소켓

# socket.bind((IP주소, 포트번호))
## UDP 서버 소켓을 특정 포트에 바인딩(bind) 하는 역할
## IP주소 -> 특정 IP주소만 들어올 수 있도록 허용
### '' -> 모든 IP주소 들어올 수 있도록 허용

serverPort = 12000
serverSocket = socket(AF_INET, SOCK_DGRAM)
serverSocket.bind( ('', serverPort) )
print("The server is ready to receive")

# message를 받고 대문자로 변환 후 다시 보낸다.
## serverSocket.recvfrom(i)
### 최대 i바이트까지 데이터를 받을 수 있도록 설정 

while 1:
    message, clientAddress = serverSocket.recvfrom(2048)
    modifiedMessage = message.upper()
    serverSocket.sendto(modifiedMessage, clientAddress)