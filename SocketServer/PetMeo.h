#pragma once
#include "PetColong.h"
class PetMeo : public PetColong
{
public:
	PetMeo();
	std::string getPetSound() override;
private:
	~PetMeo();

};

