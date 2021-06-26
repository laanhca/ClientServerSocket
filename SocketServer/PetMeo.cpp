#include "PetMeo.h"



PetMeo::PetMeo(std::string pPetName) : PetColong(pPetName)
{
}

std::string PetMeo::getPetSound()
{
    return "meo meo";
}

PetMeo::~PetMeo()
{
}
