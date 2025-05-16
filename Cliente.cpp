#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <winsock2.h>
#include <stdio.h>

#pragma comment(lib, "ws2_32.lib")

int main(){

WSADATA wsa;
SOCKET  s;
struct sockaddr_in server;
char buffer [2000];

WSAStartup(MAKEWORD(2,2), &wsa);

s = socket(AF_INET, SOCK_STREAM, 0);

server.sin_addr.s_addr = inet_addr("192.168.18.2"); 
    server.sin_family = AF_INET;
    server.sin_port = htons(8888);

connect(s, (struct sockaddr *)&server, sizeof(server));

recv(s, buffer, sizeof(buffer), 0);
printf("Recebido do servidor: %s", buffer);


closesocket(s);
WSACleanup();

return 0;




}