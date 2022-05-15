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
int cod, pret;
char nume[100];
cout<<"introdu cod";
cin>>cod;
cout<<"introdu nume";
cin>>nume;
cout<<"introdu pret";
cin>>pret;
Produs produs;
produs=Produs(cod,nume,pret);
produsService.addProdus(produs);
};

void UI::remove() {
    int cod;
cout<<"introdu cod";
cin>>cod;
produsService.removeProduct(cod);
}

void UI::update() {
    int cod, pret;
    char nume[100];
    cout<<"introdu cod";
    cin>>cod;
    cout<<"introdu nume";
    cin>>nume;
    cout<<"introdu pret";
    cin>>pret;
    Produs produs;
    produs=Produs(cod,nume,pret);
    produsService.updateProdus(produs);
}

void UI::showAll() {
    vector<Produs>all;
all=produsService.getAll();
for(int i=0;i<produsService.getSize();i++){
    cout<<all[i].getCod()<<' '<<all[i].getNume()<<' '<<all[i].getPret()<<"\n";}

}

void UI::get() {
    int cod;
    cout<<"introdu cod";
    cin>>cod;
    Produs produs;
    produs=produsService.getProdus(cod);
    cout<<produs.getCod()<<' '<<produs.getNume()<<' '<<produs.getPret()<<"\n";
}

void UI::getSize() {
cout<<produsService.getSize();
}

void UI::help() {
cout<<" 1 add, 2 remove, 3 update, a showall, p show product by code, s show size, x exit, h help\n";
    cout<<"4 add, 5 remove, 6 update, 7 delete, A showall, b show bani by valaore, S show size, R rest din un nr introdus de la tastatura\n";
    cout<<"r get rest, 8 add credit, 9 buy product, l show credit,\n";
}

void UI::run() {
    bool run= true;
    this->help();
    while (run) {
        char option;
        cin>>option;
        switch(option)
        {
            case 'x':
            {
                run= false;
                break;}
            case '1':{
                this->add();
                break;}
            case '2':
            {this->remove();
                break;}
            case '3':
            {this->update();
                break;}
            case 'h':
            {this->help();
                break;}
            case 'a':
            {this->showAll();
                break;}
            case 's':
            {this->getSize();
                break;}
            case 'p':
                {this->get();
                    break;}
            case '4':{
                this->addB();
                break;}
            case '5':
            {this->removeB();
                break;}
            case '6':
            {this->updateB();
                break;}
            case '7':
            {
                this->del();
                break;}

            case 'A':
            {this->showAllB();
                break;}
            case 'S':
            {this->getSizeB();
                break;}
            case 'b':
            {this->getB();
                break;}
            case 'R':
            {this->rest();
                break;}
            case 'r':
            {this->getRest();
                break;}
            case '9':
            {this->buy();
                break;}
            case '8':
            {this->addCredit();
                break;}
            case 'l':
            {this->showCredit();
                break;}
            default:
                cout<<"optiune invalida";

        }


}




}

void UI::updateB() {
int valaore,cantitate;
cout<<"introdu valoare";
cin>>valaore;
cout<<"introdu cantitate";
cin>>cantitate;
Bani bani;
bani=Bani(valaore,cantitate);
baniService.updateBani(bani);

}

void UI::addB() {
    unsigned int valaore,cantitate;
    cout<<"introdu valoare";
    cin>>valaore;
    cout<<"introdu cantitate";
    cin>>cantitate;
    Bani bani;
    bani=Bani(valaore,cantitate);
    baniService.addBani(bani);
}

void UI::removeB() {
    unsigned int valaore,cantitate;
    cout<<"introdu valoare";
    cin>>valaore;
    cout<<"introdu cantitate";
    cin>>cantitate;
    Bani bani;
    bani=Bani(valaore,cantitate);
    baniService.removeBani(bani);
}

void UI::getB() {
    unsigned int valaore;
    cout<<"introdu valaore";
    cin>>valaore;
    Bani bani;
    bani=baniService.getBani(valaore);
    cout<<bani.getValaore()<<' '<<bani.getCantitate()<<"\n";
}

void UI::showAllB() {
    vector<Bani>all;
    all=baniService.getAll();
    all=baniService.getAll();
    for(int i=0;i<baniService.getSize();i++){
        cout<<all[i].getValaore()<<' '<<all[i].getCantitate()<<"\n";}

}

void UI::del() {
    unsigned int valaore;
    cout<<"introdu valoare";
    cin>>valaore;
    baniService.delBani(valaore);
}

void UI::getSizeB() {
cout<<baniService.getSize();
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
cout << "introduceti valaorea";
int val;
cin>>val;
Bani bani;
bani.setCantitate(1);
bani.setValoare(val);
service.addCredit(bani);
}

void UI::showCredit() {
cout<<service.showCredit();
}

/**
 * da rest creditele ramase
 */
void UI::getRest() {



    std::vector<Bani> rest;
    rest=service.getRest();
    int n;
    n= rest.size();
    for(int i=0; i<n; i++)
        cout << rest[i].getValaore() << ' ' << rest[i].getCantitate() << "\n";
}

void UI::buy() {
cout<<"dati codul produsului pe care vreti sa il cumparati";
int cod;
cin>>cod;
service.buy(cod);
}
