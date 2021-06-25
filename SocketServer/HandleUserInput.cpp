#include "HandleUserInput.h"

HandleUserInput::HandleUserInput( SOCKET pClientSocket):clientSocket(pClientSocket) {
	listNamePet = { "cho","meo","heo", "chuot hamster", "chon","ca vang", "ca koi", "ca heo", "ca sau", "ca voi", "ga","vit","chim bo cau","vet","chim cong","chim dai bang" };
	petOfUser = nullptr;
	createPet();
	
}
HandleUserInput::~HandleUserInput() {};
void HandleUserInput::sendMess(std::string mess) {
		
		 int n = mess.length();
		char arr[4096];


		int i;
		for (i = 0; i < n; i++) {
			arr[i] = mess[i];

		}
		send(clientSocket, arr, n, 0);
	
}
void HandleUserInput::handleInput(std::string userInput) {
	if (userInput.compare("keu") == 0) {
		playSound();
		return;
	}
	if (isDoSwap(userInput)) {
		swapPet(userInput);
		return;
	}
	if ( !isInListPet(userInput)) {
		sendMess("cua hang khong co pet nay");
		return;
		
	}else
		buyPet(userInput);
	
	
	
}
bool HandleUserInput::isInListPet(std::string petName) {
	for (int i = 0; i < listNamePet.size(); i++) {
		if (petName.compare(listNamePet.at(i)) == 0) {
			return true;
		}
	}
	return false;
		
}

void HandleUserInput::buyPet(std::string userInput)
{
	if (petOfUser == nullptr) {
		
		for (int i = 0; i < listPet.size(); i++) {
			if (listPet.at(i)->getPetName().compare(userInput) == 0) {
				sendMess("da ban cho ban 01 " + userInput);
				petOfUser = listPet.at(i);
				return;
			}
		}
		
	}
	else {
		
		sendMess("ban da co pet");
	}
	
}

void HandleUserInput::swapPet(std::string userInput)
{
	if (petOfUser == nullptr) {
		sendMess("ban chua mua thu cung,  vui long nhap ten thu cung muon mua ");
		return;
	}

	//lay ten pet tu input
	std::string s;
	for (int j = 5; j <userInput.length(); j++) {
		s = s + userInput[j];
		
	}

	//kiem tra ten pet
	if (!isInListPet(s)) {
		sendMess("cua hang khong co Pet nay");
		return;
	}
	if (s.compare(petOfUser->getPetName())==0) {
		sendMess("ban dang so huu" + s);
		
		}
	else
	{
		for (int i = 0; i < listPet.size(); i++) {
			if (listPet.at(i)->getPetName().compare(s) == 0) {
				sendMess("ban da doi thanh " + s);
				petOfUser = listPet.at(i);
				return;
			}
		}

	}
		
			
}

	





void HandleUserInput::playSound()
{
	if (petOfUser != nullptr) {
		sendMess(petOfUser->getPetSound());
		
	}else
		sendMess("ban chua mua thu cung, vui long nhap thu cung muon mua");
}

void HandleUserInput::createPet()
{
	for (int i = 0; i < listNamePet.size(); i++) {
		auto pet = new Pet(listNamePet.at(i));
		listPet.push_back(pet);

	}
}

bool HandleUserInput::isDoSwap(std::string userInput)
{
	if (userInput.length() < 4) {
		return false;
	}
	std::string s;
	for(int j=0; j < 4; j++) {
		s=s+ userInput[j];
	}
	if (s.compare("swap")==0) {
		return true;
	}
	return false;
	
}
