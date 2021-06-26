#include "PetCaHeo.h"

PetCaHeo::PetCaHeo(std::string pPetName): PetBietBoi(pPetName)
{
}

std::string PetCaHeo::getPetSound()
{
    return "toi la ca heo";
}

PetCaHeo::~PetCaHeo()
{
}
