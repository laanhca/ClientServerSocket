#pragma once

#include <iostream>
using namespace std;
class Pet
{
public:
	virtual std::string getPetSound()=0;
	Pet(std::string pPetName);
	std::string getPetName() {
		return petName;
	}
protected:
	std::string petName;
	~Pet();
};

