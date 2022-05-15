//
// Created by Tomse Cosmin on 05.05.2022.
//
#include "produs.h"
#include "repo.h"
#ifndef INC_7_SERVICEPRODUS_H
#define INC_7_SERVICEPRODUS_H


class ProdusService {
private:
    Repo<Produs> &repo;

public:

    explicit ProdusService(Repo<Produs> &otherRepository) : repo{otherRepository}{};

    /**
     * Destructor
     */
    ~ProdusService() = default;


    void addProdus(const Produs& p);


    void removeProduct(int cod);

    /**
     * inlocuieste un produs cu un produs nou cu acelasi cod
     */
    void updateProdus(Produs p);






    std::vector<Produs> getAll();


    int getSize();

/**
 * get un produs dupa cod
 * @param cod
 * @return produs
 */
    Produs getProdus(int cod);
};

#endif //INC_7_SERVICEPRODUS_H
