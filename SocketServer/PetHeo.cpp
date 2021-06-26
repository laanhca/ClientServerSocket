#include "PetHeo.h"

PetHeo::PetHeo(std::string pPetName) : PetColong(pPetName)
{
}

std::string PetHeo::getPetSound()
{
    return "ngoac ngoac";
}

PetHeo::~PetHeo()
{
}
