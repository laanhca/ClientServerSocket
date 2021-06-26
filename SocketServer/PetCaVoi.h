#pragma once
#include "PetBietBoi.h"
class PetCaVoi : public PetBietBoi
{
public:
	PetCaVoi(std::string pPetName);
	std::string getPetSound() override;
private:
	~PetCaVoi();
};

