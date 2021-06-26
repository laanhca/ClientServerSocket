#pragma once
#include "PetCoCanh.h"
class PetVet : public PetCoCanh
{
public:
	PetVet(std::string pPetName);
	std::string getPetSound() override;
private:
	~PetVet();
};


