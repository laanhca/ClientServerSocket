#pragma once
#include "Pet.h"
#include <vector>
class PetManager
{
public:
	static Pet* createPet(int id);
	//std::vector<string> listNamePet;
	static enum ePet {
		CHO ,
        MEO,
        HEO,
        CHUOT,
        CHON,
        CAVANG,
        CAKOI,
        CAHEO,
        CASAU,
        CAVOI,
        GA,
        VIT,
        CHIMBOCAU,
        VET,
        CHIMCONG,
        CHIMDAIBANG,
        MAXPET

	};
};
