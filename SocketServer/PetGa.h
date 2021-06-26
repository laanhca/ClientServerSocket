#pragma once
#include "PetCoCanh.h"
class PetGa: public PetCoCanh
{
public:
	PetGa(std::string pPetName);
	std::string getPetSound() override;
private:
	~PetGa();
};

