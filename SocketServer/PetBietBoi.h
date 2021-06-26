#pragma once
#include "Pet.h"
class PetBietBoi: public Pet
{
public:
	PetBietBoi(std::string pPetName);
	virtual void petBoi();
protected:
	~PetBietBoi();
};

