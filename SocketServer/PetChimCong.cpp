#include "PetChimCong.h"

PetChimCong::PetChimCong(std::string pPetName) : PetCoCanh(pPetName)
{
}

std::string PetChimCong::getPetSound()
{
    return "toi la chim cong k phai thu";
}

PetChimCong::~PetChimCong()
{
}
