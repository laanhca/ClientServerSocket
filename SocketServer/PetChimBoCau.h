#pragma once
#include "PetCoCanh.h"
class PetChimBoCau : public PetCoCanh
{
public: 

	PetChimBoCau();
	std::string getPetSound() override;
private:
	~PetChimBoCau();
};


