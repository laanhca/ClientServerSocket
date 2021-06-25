#include "Pet.h"

void Pet::playPetSound()
{
	cout << "Toi la " + petName;
}

Pet::Pet(std::string pPetName): petName(pPetName)
{
}

Pet::~Pet()
{
}
