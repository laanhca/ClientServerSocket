#include "Main.h"
#include <WS2tcpip.h>
#include <iostream>
#include "HandleUserInput.h"
#pragma comment (lib, "ws2_32.lib")

using namespace std;

void main() {
	//khởi tạo winsock
	WSADATA wsData;
	WORD ver = MAKEWORD(2, 2);

	int wsOk = WSAStartup(ver, &wsData);
	if (wsOk != 0)
	{
		cerr << "Không thể khởi tạo winsock, đang thoát" << endl;

	}

	// tạo socket
	SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);
	if (listening == INVALID_SOCKET)
	{
		cerr << "Không thể tạo socket, đang thoát" << endl;
		return;
	}

	// liên kết địa chỉ ip và port đến socket
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(54000);
	hint.sin_addr.S_un.S_addr = INADDR_ANY;  // có thể sử dung inet_pton

	bind(listening, (sockaddr*)&hint, sizeof(hint));

	// thông báo cho winsock răng socket này để lắng nghe
	listen(listening, SOMAXCONN);

	// đợi kết nối từ client
	sockaddr_in client;
	int clientSize = sizeof(client);

	SOCKET clientSocket = accept(listening, (sockaddr*)&client, &clientSize);

	char host[NI_MAXHOST]; // tên client đã kết nối
	char service[NI_MAXSERV]; // service là port mà client đang kết nối

	ZeroMemory(host, NI_MAXHOST); // same as memset(host, 0, NI_MAXHOSR)
	ZeroMemory(service, NI_MAXSERV);

	if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) ==0)
	{
		cout << host << "connected on port" << service << endl;

	}
	else
	{
		inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
		cout << host << "connected on port" << ntohs(client.sin_port) << endl;

	}

	// đóng listening socket
	closesocket(listening);

	//vòng lặp chấp nhận và gửi tin nhắn cho client
	char buf[4096];
	
	while (true) 
	{
		ZeroMemory(buf, 4096);

		
		// đợi client gửi data
		int bytesReceived = recv(clientSocket, buf, 4096, 0);
		if (bytesReceived == SOCKET_ERROR)
		{
			cerr << "Error in recv(). Quiting" << endl;
			break;
		}
		if (bytesReceived == 0)
		{
			cout << "Client Disconnected" << endl;

			break;
		}

		cout << string(buf, 0, bytesReceived) << endl;

		//gửi lại tb cho client
		//send(clientSocket, buf, bytesReceived + 1, 0);
		
		HandleUserInput* handle = new HandleUserInput(string(buf, 0, bytesReceived), clientSocket);
		
		//handle->sendMess("vui long nhap thu cung muon mua: ");
		handle->handleInput();



	}
	
	//đóng socket
	closesocket(clientSocket);

	//cleanup winsock
	WSACleanup();
	system("pause");


}

