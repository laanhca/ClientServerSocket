#pragma once
#include "PetColong.h"
class PetMeo : public PetColong
{
public:
	PetMeo(std::string pPetName);
	std::string getPetSound() override;
private:
	~PetMeo();

};

