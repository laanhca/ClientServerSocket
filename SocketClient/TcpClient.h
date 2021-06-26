#include <iostream>
#include <WS2tcpip.h>
#include <string>
#pragma comment(lib, "ws2_32.lib")

using namespace std;

class TcpClient
{
public:
	TcpClient();
	void init();
	void sendMess(std::string userInput);
	void receiveMess();
private:

	
	string ipAddress;
	int port;
	char buf[4096];
	int sendResult;
	SOCKET sock;
	~TcpClient();
};

