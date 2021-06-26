#pragma once
#include "PetBietBoi.h"
class PetCaKoi : public PetBietBoi
{
public:

	PetCaKoi(std::string pPetName);
	std::string getPetSound() override;
private:
	~PetCaKoi();
};

