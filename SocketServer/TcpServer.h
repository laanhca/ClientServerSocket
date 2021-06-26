#pragma once

#include "Main.h"
#include <WS2tcpip.h>
#include <iostream>
#include "HandleUserInput.h"
#pragma comment (lib, "ws2_32.lib")

using namespace std;

class TcpServer
{
public:
	TcpServer();
	void init();
	void sendMess(std::string userInput);
	void receiveData();
	SOCKET getClientSocket() {
		return clientSocket;
	}
	std::string getdataFromClient() {
		return dataFromClient;
	}
	bool getStatusError() {
		return isError;
	}
private:
	SOCKET listening;
	SOCKET clientSocket;
	char buf[4096];
	std::string dataFromClient;
	bool isError=false;
	~TcpServer();
};

