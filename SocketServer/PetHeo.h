#pragma once
#include "PetColong.h"
class PetHeo : public PetColong
{
public:
	PetHeo(std::string pPetName);
	std::string getPetSound() override;
private:
	~PetHeo();

};

