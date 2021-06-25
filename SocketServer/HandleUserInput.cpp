#include "HandleUserInput.h"

HandleUserInput::HandleUserInput(std::string pUserInput, SOCKET pClientSocket):userInput(pUserInput),clientSocket(pClientSocket) {
	listNamePet = { "cho","meo","heo", "chuot hamster", "chon","ca vang", "ca koi", "ca heo", "ca sau", "ca voi", "ga","vit","chim bo cau","vet","chim cong","chim dai bang" };
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
void HandleUserInput::handleInput() {
	
	if ( isInListPet(userInput)) {
		buyPet();
	}
	if (userInput.compare("keu") == 0) {
		playSound();
	}
	
}
bool HandleUserInput::isInListPet(std::string petName) {
	for (int i = 0; i < listNamePet.size()+1; i++) {
		if (petName.compare(listNamePet.at(i)) == 0) {
			return true;
		}
	}
	return false;
		
}

void HandleUserInput::buyPet()
{
	if (numberPetOfUser != 1) {
		sendMess("ban da co pet");
	}
	else {
		sendMess("da ban cho ban 01 " + userInput);
		for (int i = 0; i < listPet.size()+1; i++) {
			if (listPet.at(i)->getPetName().compare(userInput) == 0) {
				petOfUser = listPet.at(i);
			}
		}
		numberPetOfUser = 1;
	}
	
}

void HandleUserInput::swapPet()
{
}

void HandleUserInput::playSound()
{
	if (numberPetOfUser == 1) {
		petOfUser->playPetSound();
	}else
		sendMess("ban chua mua thu cung, vui long nhap thu cung muon mua");
}

void HandleUserInput::createPet()
{
	for (int i = 0; i < listNamePet.size()+1; i++) {
		Pet* pet = new Pet(listNamePet.at(i));
		listPet.push_back(pet);

	}
}
