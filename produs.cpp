//
// Created by Tomse Cosmin on 19.04.2022.
//

#include "produs.h"

Produs::Produs() {
this->cod = 0;
this->nume = "nume";
this->pret = 0;
}

Produs::Produs(unsigned int cod, std::string nume, unsigned int pret) {
    this->cod = cod;
    this->nume = nume;
    this->pret = pret;
}

Produs::Produs(const Produs &other) {
    this->cod = other.cod;
    this->nume = other.nume;
    this->pret = other.pret;
}

Produs::~Produs() {
}

void Produs::setCod(unsigned int cod) {
    this->cod = cod;
}

void Produs::setNume(std::string nume) {
    this->nume = nume;
}

void Produs::setPret(unsigned int pret) {
    this->pret = pret;
}
