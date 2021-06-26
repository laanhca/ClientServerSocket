#pragma once
#include "Pet.h"
class PetCoCanh: public Pet
{
public:
	PetCoCanh(std::string pPetName);
	virtual void petBay();
protected:
	~PetCoCanh();
};

