#pragma once
#include "Pet.h"
#include <vector>
class PetManager
{
public:
	static Pet* createPet(std::string newPet);
	//std::vector<string> listNamePet;
};

