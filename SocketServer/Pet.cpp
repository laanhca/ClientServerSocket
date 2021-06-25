#include "Pet.h"

std::string Pet::getPetSound()
{
	return  "Toi la " + petName;
}

Pet::Pet(std::string pPetName): petName(pPetName)
{
}

Pet::~Pet()
{
}
