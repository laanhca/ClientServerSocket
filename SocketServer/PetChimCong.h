#pragma once
#include "PetCoCanh.h"
class PetChimCong : public PetCoCanh
{
public:
	PetChimCong();
	std::string getPetSound() override;
private:
	~PetChimCong();
};


