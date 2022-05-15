//
// Created by Tomse Cosmin on 09.05.2022.
//

#include "ServiceTranzactie.h"
#include "produs.h"
#include "bani.h"
#include "Service bani.h"
#include "ServiceProdus.h"
#include "repo.h"
#include "repoBani.h"
#include <vector>

void Service::addCredit(const Bani &bani) {
    baniService.addBani(bani);
    this->credit += bani.getValaore();
}

std::vector<Bani> Service::getRest() {
    std::vector<Bani> rest;
    rest=baniService.rest(this->credit);
    this->credit = 0 ;


    return rest;
}

void Service::buy(unsigned int cod) {
    Produs produs;
    produs = produsService.getProdus(cod);
    int pret= produs.getPret();
    if(this->credit >= pret) {
        this->credit -= pret;
        produsService.removeProduct(cod);
    }


}

int Service::showCredit() {
    return this->credit;
}

