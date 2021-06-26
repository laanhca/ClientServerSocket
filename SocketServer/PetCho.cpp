#include "PetCho.h"

PetCho::PetCho(std::string pPetName) : PetColong(pPetName)
{
}

std::string PetCho::getPetSound()
{
    return "gau gau";
}

PetCho::~PetCho()
{
}
