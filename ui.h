//
// Created by Tomse Cosmin on 05.05.2022.
//
#ifndef INC_7_UI_H
#define INC_7_UI_H

#include "produs.h"
#include "bani.h"
#include "Service bani.h"
#include "ServiceProdus.h"
#include "repo.h"
#include "repoBani.h"
#include "ServiceTranzactie.h"

class UI{
private:
    ProdusService &produsService;
    BaniService &baniService;
    Service &service;
public:
    explicit UI(ProdusService &_produsService, BaniService &_baniService, Service &_service ) : produsService {_produsService},baniService {_baniService}, service {_service}{};

    bool stringValidator(const std::string& string);
    bool isNumber(const std::string& str);
    static bool moneyValidator(int val);

    void add();
    void remove();
    void update();
    void showAll();
    void get();
    void getSize();
    static void help();
    void run();
    ~UI() = default;
    void addB();
    void removeB();
    void updateB();
    void del();
    void showAllB();
    void getB();
    void getSizeB();
    void rest();
    void addCredit();
    void showCredit();
    void getRest();
    void buy();
};


#endif //INC_7_UI_H
