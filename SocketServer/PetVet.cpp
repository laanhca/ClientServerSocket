#include "PetVet.h"

PetVet::PetVet(std::string pPetName) : PetCoCanh(pPetName)
{

}

std::string PetVet::getPetSound()
{
    return "anh dzai";
}

PetVet::~PetVet()
{
}
