//
// Created by Tomse Cosmin on 09.05.2022.
//

#ifndef INC_7_SERVICETRANZACTIE_H
#define INC_7_SERVICETRANZACTIE_H

#include "produs.h"
#include "bani.h"
#include "Service bani.h"
#include "ServiceProdus.h"
#include "repo.h"
#include "repoBani.h"
#include <vector>

class Service{
private:
    ProdusService &produsService;
    BaniService &baniService;
    int credit=0;
public:
    explicit Service(ProdusService &_produsService, BaniService &_baniService ) : produsService {_produsService},baniService {_baniService}{};
    void addCredit(const Bani &bani);
    std::vector<Bani> getRest();
    void buy(unsigned int cod);
    int showCredit();
};

#endif //INC_7_SERVICETRANZACTIE_H
