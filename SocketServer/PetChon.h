#pragma once
#include "PetColong.h"
class PetChon : public PetColong
{
public:
	PetChon(std::string pPetName);
	std::string getPetSound() override;
private:
	~PetChon();

};

