//
// Created by Tomse Cosmin on 07.05.2022.
//

#include "bani.h"

Bani::Bani() {
    this->valoare = 0;
    this->cantitate = 0;

}

Bani::Bani(unsigned int valoare, unsigned int cantitate) {
    this->valoare = valoare;
    this->cantitate = cantitate;

}

Bani::Bani(const Bani &other) {
    this->valoare = other.valoare;
    this->cantitate = other.cantitate;
}

Bani::~Bani() = default;

void Bani::setValoare(unsigned int val) {
    this->valoare = val;
}

void Bani::setCantitate(unsigned int _cantitate) {
    this->cantitate = _cantitate;
}
