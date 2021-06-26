#pragma once
#include "PetBietBoi.h"
class PetCaVoi : public PetBietBoi
{
public:
	PetCaVoi();
	std::string getPetSound() override;
private:
	~PetCaVoi();
};

