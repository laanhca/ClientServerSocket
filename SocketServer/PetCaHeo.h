#pragma once
#include "PetBietBoi.h"
class PetCaHeo: public PetBietBoi
{
public:

	PetCaHeo();
	std::string getPetSound() override;
private:
	~PetCaHeo();
};

