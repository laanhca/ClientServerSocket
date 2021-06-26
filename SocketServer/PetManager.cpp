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

Pet* PetManager::createPet(int ePet)
{
    switch (ePet)
    {
    case ePet::CHO:
        return new PetCho();
    case ePet::MEO:
        return new PetMeo();
    case ePet::HEO:
        return new PetHeo();
    case ePet::CHUOT:
        return new PetChuot();
    case ePet::CHON:
        return new PetChon();
    case ePet::CAVANG:
        return new PetCaVang();
    case ePet::CAKOI:
        return new PetCaKoi();
    case ePet::CAHEO:
        return new PetCaHeo();
    case ePet::CASAU:
        return new PetCaSau();
    case ePet::CAVOI:
        return new PetCaVoi();
    case ePet::GA:
        return new PetGa();
    case ePet::VIT:
        return new PetVit();
    case ePet::CHIMBOCAU:
        return new PetChimBoCau();
    case ePet::VET:
        return new PetVet();
    case ePet::CHIMCONG:
        return new PetChimCong();
    case ePet::CHIMDAIBANG:
        return new PetChimDaiBang();
    default:
        return nullptr;
    }




}