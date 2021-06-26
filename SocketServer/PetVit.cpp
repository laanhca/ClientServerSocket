#include "PetVit.h"



PetVit::PetVit(std::string pPetName): PetCoCanh(pPetName)
{
}

std::string PetVit::getPetSound()
{
    return "cap cap cap";
}

PetVit::~PetVit()
{
}
