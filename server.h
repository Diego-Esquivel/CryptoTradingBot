/********************************************************************************************************************************************
 *  Author: Diego G Esquivel & Eric D Smith
 *  CSCE306 Spring 2022 - Object Oriented Software Development
 *  Portfolio Project v.0.1: - server.h, <windows.h>, <winsock2.h>, <ws2tcpip.h>, <stdlib.h>, <stdio.h> <iostream>, <string>, <fstream>
 *  Code Summary: This code header file is the server program for the application. It uses many windows only libraries and does file I/O.
 * *****************************************************************************************************************************************/
#undef UNICODE

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

// Need to link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")
// #pragma comment (lib, "Mswsock.lib")

#define DEFAULT_BUFLEN 512*2
#define DEFAULT_PORT "126"
using namespace std;
class server {
    public:
    string run(){
        WSADATA wsaData;
    int iResult;

    SOCKET ListenSocket = INVALID_SOCKET;
    SOCKET ClientSocket = INVALID_SOCKET;

    struct addrinfo *result = NULL;
    struct addrinfo hints;

    int iSendResult;
    char recvbuf[DEFAULT_BUFLEN];
    int recvbuflen = DEFAULT_BUFLEN;
    
    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        return "1";
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

    // Resolve the server address and port
    iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
    if ( iResult != 0 ) {
        printf("getaddrinfo failed with error: %d\n", iResult);
        WSACleanup();
        return "1";
    }

    // Create a SOCKET for connecting to server
    ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (ListenSocket == INVALID_SOCKET) {
        printf("socket failed with error: %ld\n", WSAGetLastError());
        freeaddrinfo(result);
        WSACleanup();
        return "1";
    }

    // Setup the TCP listening socket
    iResult = bind( ListenSocket, result->ai_addr, (int)result->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        printf("bind failed with error: %d\n", WSAGetLastError());
        freeaddrinfo(result);
        closesocket(ListenSocket);
        WSACleanup();
        return "1";
    }

    freeaddrinfo(result);

    iResult = listen(ListenSocket, SOMAXCONN);
    if (iResult == SOCKET_ERROR) {
        printf("listen failed with error: %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return "1";
    }

    // Accept a client socket
    ClientSocket = accept(ListenSocket,(sockaddr*) NULL, NULL);
    if (ClientSocket == INVALID_SOCKET) {
        printf("accept failed with error: %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return "1";
    }

    // No longer need server socket
    closesocket(ListenSocket);
    // Receive until the peer shuts down the connection
    string recievedvalue = recvbuf;
    ifstream ifs("try.html");
    string content( (std::istreambuf_iterator<char>(ifs) ),
                       (std::istreambuf_iterator<char>()    ) );
    ifs.close();
    int length = 1;
    while(content[length-1] != '\0'){
        length++;
    }
    char* astring = new char[length];
    char* request_value = new char[DEFAULT_BUFLEN];
    for(int index = 0; index < length; index++){
        astring[index] = content[index];
    }
    

        iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
        
        if (iResult > 0) {
            printf("Bytes received: %d\n", iResult);
            request_value = recvbuf;
			iSendResult = send(ClientSocket, "HTTP/1.1 200 ALL GOOD\r\nAccess-Control-Allow-Origin: *\nConnection: Keep-Alive\r\nYes buy it all", 93, 0);
			if (iSendResult == SOCKET_ERROR) {
                printf("send failed with error: %d\n", WSAGetLastError());
                closesocket(ClientSocket);
                WSACleanup();
                return "error";
            }
            printf("Bytes sent: %d\n", iSendResult);
        }
        else if (iResult == 0)
            printf("Connection closing...\n");
        else  {
            printf("recv failed with error: %d\n", WSAGetLastError());
            closesocket(ClientSocket);
            WSACleanup();
            return "1";
        }
        recievedvalue = recvbuf;
        //cout << endl << endl << "The value:\t\t" << recievedvalue << endl << endl;
    
    

    // shutdown the connection since we're done
    iResult = shutdown(ClientSocket, SD_SEND);
    if (iResult == SOCKET_ERROR) {
        printf("shutdown failed with error: %d\n", WSAGetLastError());
        closesocket(ClientSocket);
        WSACleanup();
        return "1";
    }

    // cleanup
    closesocket(ClientSocket);
    WSACleanup();
    
    return request_value;
    }
};