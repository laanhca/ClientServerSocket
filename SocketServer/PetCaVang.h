#pragma once
#include "PetBietBoi.h"
class PetCaVang : public PetBietBoi
{
public:

	PetCaVang(std::string pPetName);
	std::string getPetSound() override;
private:
	~PetCaVang();

};

