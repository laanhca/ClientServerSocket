#pragma once
#include "PetCoCanh.h"
class PetVit : public PetCoCanh
{
public:
	PetVit();
	std::string getPetSound() override;
private:
	~PetVit();
};


