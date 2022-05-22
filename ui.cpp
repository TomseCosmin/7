//
// Created by Tomse Cosmin on 05.05.2022.
//

#include "ui.h"
#include "produs.h"
#include "repo.h"
#include "ServiceProdus.h"
#include "bani.h"
#include "repoBani.h"
#include "Service bani.h"
#include <iostream>
#include <string>

using namespace std;

void UI::add() {
    std::string cod, pret, nume;
    cout << "introdu cod";
    std::getline(std::cin, cod);
    std::getline(std::cin, cod);
    cout << "introdu nume";
    std::getline(std::cin, nume);
    cout << "introdu pret";
    std::getline(std::cin, pret);
    Produs produs;
    try{
        produs = Produs(stoi(cod), nume, stoi(pret));
        produsService.addProdus(produs);
    } catch (std::invalid_argument& e){
        std::cerr << "ERROR!!!\n";
    }
};

void UI::remove() {
    std::string cod;
    cout << "introdu cod";
    cin >> cod;
    try {
        produsService.removeProduct(std::stoi(cod));
    } catch (std::invalid_argument &e) {
        std::cerr << "ERROR\n";
    }
}

void UI::update() {
    std::string cod, pret, nume;
    cout << "introdu cod";
    std::getline(std::cin, cod);
    std::getline(std::cin, cod);
    cout << "introdu nume";
    std::getline(std::cin, nume);
    cout << "introdu pret";
    std::getline(std::cin, pret);
    Produs produs;
    try{
        produs = Produs(stoi(cod), nume, stoi(pret));
        produsService.updateProdus(produs);
    } catch (std::invalid_argument& e){
        std::cerr << "ERROR!!!";
    }
}

void UI::showAll() {
    vector<Produs> all;
    all = produsService.getAll();
    for (int i = 0; i < produsService.getSize(); i++) {
        cout << all[i].getCod() << ' ' << all[i].getNume() << ' ' << all[i].getPret() << "\n";
    }

}

void UI::get() {
    std::string cod;
    cout << "introdu cod";
    cin >> cod;
    Produs produs;
    try {
        produs = produsService.getProdus(stoi(cod));
        cout << produs.getCod() << ' ' << produs.getNume() << ' ' << produs.getPret() << "\n";
    } catch (std::invalid_argument& e) {
        std::cerr << "ERROR\n";
        return;
    }
}

void UI::getSize() {
    cout << produsService.getSize();
}

void UI::help() {
    cout << " 1 add, 2 remove, 3 update, a showall, p show product by code, s show size, x exit, h help\n";
    cout << "4 add, 5 remove, 6 update, 7 delete, A showall, b show bani by valaore, S show size, R rest din un nr introdus de la tastatura\n";
    cout << "r get rest, 8 add credit, 9 buy product, l show credit,\n";
}

void UI::run() {
    bool run = true;
    this->help();
    while (run) {
        char option;
        cin >> option;
        switch (option) {
            case 'x': {
                run = false;
                break;
            }
            case '1': {
                this->add();
                break;
            }
            case '2': {
                this->remove();
                break;
            }
            case '3': {
                this->update();
                break;
            }
            case 'h': {
                this->help();
                break;
            }
            case 'a': {
                this->showAll();
                break;
            }
            case 's': {
                this->getSize();
                break;
            }
            case 'p': {
                this->get();
                break;
            }
            case '4': {
                this->addB();
                break;
            }
            case '5': {
                this->removeB();
                break;
            }
            case '6': {
                this->updateB();
                break;
            }
            case '7': {
                this->del();
                break;
            }

            case 'A': {
                this->showAllB();
                break;
            }
            case 'S': {
                this->getSizeB();
                break;
            }
            case 'b': {
                this->getB();
                break;
            }
            case 'R': {
                this->rest();
                break;
            }
            case 'r': {
                this->getRest();
                break;
            }
            case '9': {
                this->buy();
                break;
            }
            case '8': {
                this->addCredit();
                break;
            }
            case 'l': {
                this->showCredit();
                break;
            }
            default:
                cout << "optiune invalida";

        }


    }


}

void UI::updateB() {
    try {
        std::string valaore, cantitate;
        cout << "introdu valoare";
        cin >> valaore;
        UI::moneyValidator(stoi(valaore));
        cout << "introdu cantitate";
        cin >> cantitate;
        Bani bani;
        bani = Bani(stoi(valaore), stoi(cantitate));
        baniService.updateBani(bani);
    } catch (std::invalid_argument &invalid_argument) {
        std::cerr << "error\n";
    } catch (std::exception &exception) {
        std::cerr << "error\n";
    }
}

void UI::addB() {
    try {
        std::string valaore, cantitate;
        cout << "introdu valoare";
        cin >> valaore;
        UI::moneyValidator(stoi(valaore));
        cout << "introdu cantitate";
        cin >> cantitate;
        Bani bani;
        bani = Bani(stoi(valaore), stoi(cantitate));
        baniService.addBani(bani);
    } catch (std::invalid_argument &invalid_argument) {
        std::cerr << "error\n";
    } catch (std::exception &exception) {
        std::cerr << "error\n";
    }
}

void UI::removeB() {
    try {
        std::string valaore, cantitate;
        cout << "introdu valoare";
        cin >> valaore;
        UI::moneyValidator(stoi(valaore));
        cout << "introdu cantitate";
        cin >> cantitate;
        Bani bani;
        bani = Bani(stoi(valaore), stoi(cantitate));
        baniService.removeBani(bani);
    } catch (std::invalid_argument &invalid_argument) {
        std::cerr << "error\n";
    } catch (std::exception &exception) {
        std::cerr << "error\n";
    }
}

void UI::getB() {
    try {
        std::string valaore;
        cout << "introdu valaore";
        cin >> valaore;
        UI::moneyValidator(stoi(valaore));
        Bani bani;
        bani = baniService.getBani(stoi(valaore));
        cout << bani.getValaore() << ' ' << bani.getCantitate() << "\n";
    } catch (std::invalid_argument &invalid_argument) {
        std::cerr << "error\n";
    } catch (std::exception &exception) {
        std::cerr << "error\n";
    }
}

void UI::showAllB() {
    vector<Bani> all;
    all = baniService.getAll();
    all = baniService.getAll();
    for (int i = 0; i < baniService.getSize(); i++) {
        cout << all[i].getValaore() << ' ' << all[i].getCantitate() << "\n";
    }

}

void UI::del() {
    try {
        std::string valaore;
        cout << "introdu valoare";
        cin >> valaore;
        UI::moneyValidator(stoi(valaore));
        baniService.delBani(stoi(valaore));
    }
    catch (std::invalid_argument &invalid_argument) {
        std::cerr << "error\n";
    } catch (std::exception &exception) {
        std::cerr << "error\n";
    }
}

void UI::getSizeB() {
    cout << baniService.getSize();
}

/**
 * da rest un nr dat de la tastatura
 */
void UI::rest() {


    cout << "rest din:";
    int rest;
    cin >> rest;
    vector<Bani> all;
    all = baniService.rest(rest);
    for (int i = 0; i < all.size(); i++) {
        cout << all[i].getValaore() << ' ' << all[i].getCantitate() << "\n";

    }
}

void UI::addCredit() {
    try {
        cout << "introduceti valaorea";
        std::string val;
        cin >> val;
        UI::moneyValidator(stoi(val));
        Bani bani;
        bani.setCantitate(1);
        bani.setValoare(stoi(val));
        service.addCredit(bani);
    } catch (std::invalid_argument& e){
        std::cerr << "error\n";
    } catch (std::exception& e) {
        std::cerr << "error\n";
    }
}

void UI::showCredit() {
    cout << service.showCredit();
}

/**
 * da rest creditele ramase
 */
void UI::getRest() {


    std::vector<Bani> rest;
    rest = service.getRest();
    int n;
    n = rest.size();
    for (int i = 0; i < n; i++)
        cout << rest[i].getValaore() << ' ' << rest[i].getCantitate() << "\n";
}

void UI::buy() {
    try {
        cout << "dati codul produsului pe care vreti sa il cumparati";
        std::string cod;
        cin >> cod;
        service.buy(stoi(cod));
    } catch (std::invalid_argument& e){
        std::cerr << "error\n";
    }
}

bool UI::stringValidator(const std::string& string) {
    return true;
}

bool UI::isNumber(const std::string& str) {
    for (auto c: str) {
        if (std::isdigit(c) == 0)
            return false;
    }
    return true;
}

bool UI::moneyValidator(int val) {
    if ((val == 1) || (val == 5) || (val == 10) || (val == 50) || (val == 100) || (val == 500) || (val == 1000) || (val == 2000) || (val == 5000) || (val == 10000)  || (val == 20000) || (val == 50000)) {
        return true;
    } else {
        throw std::exception();
    }
}
