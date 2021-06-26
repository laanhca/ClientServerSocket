#include "Main.h"
#include <WS2tcpip.h>
#include <iostream>
#include "HandleUserInput.h"
#include "TcpServer.h"
#pragma comment (lib, "ws2_32.lib")

using namespace std;

void main() {
	
	TcpServer* server = new TcpServer();
	HandleUserInput* handle = new HandleUserInput( server->getClientSocket());
	while (true) 
	{
		
		server->receiveData();
		if (server->getStatusError()) {
			break;
		}
		handle->handleInput(server->getdataFromClient());
	}
	
	
	


}

