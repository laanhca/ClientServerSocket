#include "TcpServer.h"

TcpServer::TcpServer()
{
	this->init();
}

void TcpServer::init()
{
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

	clientSocket = accept(listening, (sockaddr*)&client, &clientSize);

	char host[NI_MAXHOST]; // tên client đã kết nối
	char service[NI_MAXSERV]; // service là port mà client đang kết nối

	ZeroMemory(host, NI_MAXHOST); // same as memset(host, 0, NI_MAXHOSR)
	ZeroMemory(service, NI_MAXSERV);

	if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0)
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
}

void TcpServer::sendMess(std::string userInput)
{
}

void TcpServer::receiveData()
{
	ZeroMemory(buf, 4096);

	// đợi client gửi data
	int bytesReceived = recv(clientSocket, buf, 4096, 0);
	if (bytesReceived == SOCKET_ERROR)
	{
		cerr << "Error in recv(). Quiting" << endl;
		isError = true;
	}
	if (bytesReceived == 0)
	{
		cout << "Client Disconnected" << endl;
		isError = true;
	}
	
	dataFromClient = string(buf, 0, bytesReceived);
	cout << "CLIENT: " + dataFromClient << endl;
}

TcpServer::~TcpServer()
{
	closesocket(clientSocket);
	WSACleanup();
	system("pause");
}
