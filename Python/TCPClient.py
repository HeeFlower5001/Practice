from socket import *

# 서버 이름과 서버 포트 입력
# 자신의 서버 주소 -> localhost or '127.0.0.1'

serverName = '125.183.197.235'
serverPort = 12000

# 소켓 생성과 메시지 입력 
## AF_INIT -> IPv4 주소 체계 사용
## SOCK_STREAM -> TCP 소켓

clientSocket = socket(AF_INET, SOCK_STREAM)
clientSocket.connect( (serverName, serverPort) )
message = "2022125077_kim-hee-seung"


# 소켓 보내고 받기
## message를 encoding, serverName, serverPort 입력
# clientSocket.recvfrom(i)
## 최대 i바이트까지 데이터를 받을 수 있도록 설정 
## message와 serverAdress 반환

clientSocket.send(message.encode())
modifiedMessage = clientSocket.recv(1024)

# 받은 메시지를 decoding 한 후 출력
# 소켓 닫기

print('From Server: ', modifiedMessage.decode())
clientSocket.close()