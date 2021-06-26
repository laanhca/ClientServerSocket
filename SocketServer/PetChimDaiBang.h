#pragma once
#include "PetCoCanh.h"
class PetChimDaiBang : public PetCoCanh
{
public:
	PetChimDaiBang();
	std::string getPetSound() override;
private:
	~PetChimDaiBang();
};


