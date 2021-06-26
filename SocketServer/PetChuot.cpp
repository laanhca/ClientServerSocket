#include "PetChuot.h"

PetChuot::PetChuot(std::string pPetName) : PetColong(pPetName){
}

std::string PetChuot::getPetSound()
{
    return "chit chit";
}

PetChuot::~PetChuot()
{
}
