//
// Created by Tomse Cosmin on 19.04.2022.
//
#include "produs.h"
#include "repo.h"
#include <cassert>
#include <iostream>
#ifndef INC_7_TEST_H
#define INC_7_TEST_H
class Test {
public:
    static void testProdus() {
        Produs produs;
        assert(produs.getCod() == 0);
        assert(produs.getNume() == "nume");
        assert(produs.getPret() == 0);
        produs.setCod(1);
        produs.setNume("ciocolata");
        produs.setPret(10);
        assert(produs.getCod() == 1);
        assert(produs.getNume() == "ciocolata");
        assert(produs.getPret() == 10);

    }
    static void testRepo() {
        Produs produs;
        produs.setCod(1);
        produs.setNume("ciocolata");
        produs.setPret(10);
        Repo<Produs> repo;
        repo.add(produs);
        Produs produs1;
        produs1.setCod(2);
        produs1.setNume("alune");
        produs1.setPret(3);
        repo.add(produs1);
        std::vector<Produs> verifica=repo.getAll(produs);
        assert(verifica[0].getCod() == 1);
        assert(verifica[0].getNume() == "ciocolata");
        assert(verifica[0].getPret() == 10);



    }
    static void testALll() {
        Test::testProdus();
        Test::testRepo();
        std::cout<<"testare reusita";
    }
};
#endif //INC_7_TEST_H
