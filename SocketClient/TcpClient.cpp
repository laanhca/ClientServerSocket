#include "TcpClient.h"

TcpClient::TcpClient()
{
	this->init();
}

void TcpClient::init()
{
	ipAddress = "127.0.0.1"; //ip của sv
	port = 54000; // port đang lắng nghe của sv

	//khởi tạo winsock
	WSAData data;
	WORD ver = MAKEWORD(2, 2);
	int wsResult = WSAStartup(ver, &data);
	if (wsResult != 0)
	{
		cerr << "không thể tạo winsock, lỗi #" << wsResult << endl;
		return;
	}

	// tạo socket
	 sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == INVALID_SOCKET)
	{
		cerr << "Không thể tạo socket, lỗi #" << WSAGetLastError() << endl;
		WSACleanup();
		return;
	}

	//điền vào hint structure
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(port);
	inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

	//kết nối đến sv
	int connResult = connect(sock, (sockaddr*)&hint, sizeof(hint));
	if (connResult == SOCKET_ERROR)
	{
		cerr << "Cua hang dong cua vui long quay lai sau" << endl;
		closesocket(sock);
		WSACleanup();
		return;
	}

}

void TcpClient::sendMess(std::string userInput)
{
	if (userInput.size() > 0)
	{
		//gửi văn bản
		sendResult = send(sock, userInput.c_str(), userInput.size() + 1, 0);
	}
}

void TcpClient::receiveMess()
{
	if (sendResult != SOCKET_ERROR)
	{
		//đợi máy chủ phản hồi
		ZeroMemory(buf, 4096);

		int bytesReceived = recv(sock, buf, 4096, 0);

		if (bytesReceived > 0)
		{
			//tb đến console
			cout << "SERVER: " << string(buf, 0, bytesReceived) << endl;

		}


	}
}


TcpClient::~TcpClient()
{
	closesocket(sock);
	WSACleanup;
}
