#pragma once
#include "PetCoCanh.h"
class PetVit : public PetCoCanh
{
public:
	PetVit(std::string pPetName);
	std::string getPetSound() override;
private:
	~PetVit();
};


