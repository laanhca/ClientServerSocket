#include "PetChimBoCau.h"

PetChimBoCau::PetChimBoCau(std::string pPetName) : PetCoCanh(pPetName)
{
}

std::string PetChimBoCau::getPetSound()
{
    return "chip chip";
}

PetChimBoCau::~PetChimBoCau()
{
}
