
#include <WS2tcpip.h>
#include <iostream>
#include<vector>
#pragma once
using namespace std;
#include "Pet.h"
class HandleUserInput
{
public:
	HandleUserInput( SOCKET pClientSocket);
	void sendMess(std::string mess);
	void handleInput(std::string userInput);
	bool isInListPet(std::string petName);
	void buyPet(std::string userInput);
	void swapPet(std::string userInput);
	void playSound();
	void createPet();
	bool isDoSwap(std::string userInput);

private:
	~HandleUserInput();
	//std::string userInput;
	SOCKET clientSocket;
	int numberPetOfUser=0;
	std::vector<Pet*> listPet;
	Pet* petOfUser;
	enum ePet {

	};
};

