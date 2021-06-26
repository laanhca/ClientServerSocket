#include "PetChon.h"

PetChon::PetChon(std::string pPetName) : PetColong(pPetName)
{
}

std::string PetChon::getPetSound()
{
	return "toi la chon";
}

PetChon::~PetChon()
{
}
