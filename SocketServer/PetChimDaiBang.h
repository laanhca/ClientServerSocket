#pragma once
#include "PetCoCanh.h"
class PetChimDaiBang : public PetCoCanh
{
public:
	PetChimDaiBang(std::string pPetName);
	std::string getPetSound() override;
private:
	~PetChimDaiBang();
};


