#pragma once

#include <iostream>
using namespace std;
class Pet
{
public:
	std::string getPetSound();
	Pet(std::string pPetName);
	std::string getPetName() {
		return petName;
	}
private:
	std::string petName;
	~Pet();
};

