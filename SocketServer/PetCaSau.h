#pragma once
#include "PetBietBoi.h"
class PetCaSau : public PetBietBoi
{
public:

	PetCaSau();
	std::string getPetSound() override;
private:
	~PetCaSau();
};

