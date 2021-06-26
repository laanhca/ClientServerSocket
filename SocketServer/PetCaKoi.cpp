#include "PetCaKoi.h"



PetCaKoi::PetCaKoi(std::string pPetName): PetBietBoi(pPetName)
{
}

std::string PetCaKoi::getPetSound()
{
    return "toi la ca koi";
}

PetCaKoi::~PetCaKoi()
{
}
