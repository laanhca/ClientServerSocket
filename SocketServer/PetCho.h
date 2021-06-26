#pragma once
#include "PetColong.h"
class PetCho : public PetColong
{
public:
	PetCho();
	std::string getPetSound() override;
private:
	~PetCho();

};

