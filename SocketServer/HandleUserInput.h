
#include <WS2tcpip.h>
#include <iostream>
#include<vector>
#pragma once
using namespace std;
#include "Pet.h"
class HandleUserInput
{
public:
	HandleUserInput(std::string pUserInput, SOCKET pClientSocket);
	void sendMess(std::string mess);
	void handleInput();
	bool isInListPet(std::string petName);
	void buyPet();
	void swapPet();
	void playSound();
	void createPet();

private:
	~HandleUserInput();
	std::string userInput;
	SOCKET clientSocket;
	int numberPetOfUser=0;
	std::vector<string> listNamePet;
	std::vector<Pet*> listPet;
	Pet* petOfUser;
};

