#include "PetCaVoi.h"
PetCaVoi::PetCaVoi(std::string pPetName) : PetBietBoi(pPetName) {

}
std::string PetCaVoi::getPetSound()
{
    return "toi la ca voi";
}

PetCaVoi::~PetCaVoi()
{
}
