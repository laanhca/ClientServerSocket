#pragma once
#include "Pet.h"
class PetColong: public Pet
{
public:
	PetColong(std::string pPetName);
	virtual void ruLong();
protected:
	~PetColong();
};

