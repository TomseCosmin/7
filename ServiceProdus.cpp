//
// Created by Tomse Cosmin on 05.05.2022.
//

#include "ServiceProdus.h"
#include "produs.h"

void ProdusService::addProdus(const Produs& p) {
this->repo.add(p);
}

void ProdusService::removeProduct(int cod) {
this->repo.remove(cod);
}

std::vector<Produs> ProdusService::getAll() {
    Produs produs;
    return this->repo.getAll(produs);
}

void ProdusService::updateProdus(Produs p) {
    this->repo.update(p);
}

int ProdusService::getSize() {
    return this->repo.getSize();
}



Produs ProdusService::getProdus(int cod) {
    return this->repo.get(cod);
}

