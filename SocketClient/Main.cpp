#include "Main.h"
#include "TcpClient.h"
void main() {
	TcpClient* client = new TcpClient();
	string userInput;
	int i = 0;
	do
	{
		i++;
		if (i == 1) {
			cout << "vui long nhap thu cung muon mua: ";
		}
		// Prompt the user for some text
		cout << "> ";
		getline(cin, userInput);
		client->sendMess(userInput);
		client->receiveMess();

	} while (userInput.size() > 0);

}