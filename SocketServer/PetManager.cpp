#include "PetManager.h"
#include "PetCaKoi.h"
#include "PetCaHeo.h"
#include "PetCaSau.h"
#include "PetCaVang.h"
#include "PetCaVoi.h"
#include "PetCho.h"
#include "PetMeo.h"
#include "PetHeo.h"
#include "PetChuot.h"
#include "PetChon.h"
#include "PetGa.h"
#include "PetVit.h"
#include "PetVet.h"
#include "PetChimBoCau.h"
#include "PetChimDaiBang.h"
#include "PetChimCong.h"

Pet* PetManager::createPet(std::string newPet)
{
    if (newPet.compare("cho")) {
        return new PetCho(newPet);
    }
    if (newPet.compare("meo")) {
        return new PetMeo(newPet);
    }
    if (newPet.compare("heo")) {
        return new PetHeo(newPet);
    }
    if (newPet.compare("chuot")) {
        return new PetChuot(newPet);
    }
    if (newPet.compare("chon")) {
        return new PetChon(newPet);
    }
    if (newPet.compare("ca vang")) {
        return new PetCaVang(newPet);
    }
    if (newPet.compare("ca koi")) {
        return new PetCaKoi(newPet);
    }
    if (newPet.compare("ca heo")) {
        return new PetCaHeo(newPet);
    }
    if (newPet.compare("ca sau")) {
        return new PetCaSau(newPet);
    }
    if (newPet.compare("ca voi")) {
        return new PetCaVoi(newPet);
    }
    if (newPet.compare("ga")) {
        return new PetGa(newPet);
    }
    if (newPet.compare("vit")) {
        return new PetVit(newPet);
    }
    if (newPet.compare("bo cau")) {
        return new PetChimBoCau(newPet);
    }
    if (newPet.compare("vet")) {
        return new PetVet(newPet);
    }
    if (newPet.compare("chim cong")) {
        return new PetChimCong(newPet);
    }
    if (newPet.compare("dai bang")) {
        return new PetChimDaiBang(newPet);
    }
    return nullptr;
}
