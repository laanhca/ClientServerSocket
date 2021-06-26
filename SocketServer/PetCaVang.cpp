#include "PetCaVang.h"

PetCaVang::PetCaVang(std::string pPetName) : PetBietBoi(pPetName)
{
}

std::string PetCaVang::getPetSound()
{
    return "toi la ca vang";
}

PetCaVang::~PetCaVang()
{
}
