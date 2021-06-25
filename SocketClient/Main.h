#include <iostream>
#include <WS2tcpip.h>
#include <string>
#pragma comment(lib, "ws2_32.lib")

using namespace std;

void main() {
	string ipAddress = "127.0.0.1"; //ip của sv
	int port = 54000; // port đang lắng nghe của sv

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
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
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
		cerr << "Cua hang dong cua vui long quay lai sau"  << endl;
		closesocket(sock);
		WSACleanup();
		return;
	}

	// vòng lặp để gửi và nhập data
	char buf[4096];
	string userInput;
	int i = 0;
	do
	{
		i++;
		if (i == 1) {
			cout << "vui long nhap thu cung muon mua: ";
		}
		cout << ">"; // nhắc ng dùng nhập văn bản
		getline(cin, userInput);

		if (userInput.size() > 0)
		{
			//gửi văn bản
			int sendResult = send(sock, userInput.c_str(), userInput.size() + 1, 0);
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

	} while (userInput.size() > 0);

	closesocket(sock);
	WSACleanup;

}