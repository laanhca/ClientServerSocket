#pragma once
#include "PetBietBoi.h"
class PetCaSau : public PetBietBoi
{
public:

	PetCaSau(std::string pPetName);
	std::string getPetSound() override;
private:
	~PetCaSau();
};

