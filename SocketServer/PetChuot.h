#pragma once


#include "PetColong.h"
class PetChuot : public PetColong
{
public:
	PetChuot();
	std::string getPetSound() override;
private:
	~PetChuot();

};