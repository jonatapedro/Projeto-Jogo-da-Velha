#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <winsock2.h>
#include <stdio.h>

#pragma comment(lib, "ws_32.lib") //Biblioteca de rede

int main(){
    WSADATA wsa;
    SOCKET s, new_socket;
    struct sockaddr_in server, client;
    
    int c;
    char *message = "Conectado ao servidor!\n";
    
    //Inicia o Winsock

    WSAStartup(MAKEWORD(2,2), &wsa);

    //Cria o socket

    s = socket(AF_INET, SOCK_STREAM, 0);

    //Prepara estrutura do servidor

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons (8888);

    bind(s, (struct sockaddr *)&server, sizeof(server));
    listen(s, 3);
    printf("Aguardando conexões....\n");
 
    c = sizeof(struct sockaddr_in);
    new_socket = accept(s, (struct sockaddr *)&client, &c);
    
    send(new_socket, message, strlen(message), 0);

    closesocket(s);
    WSACleanup();

    return 0;

}