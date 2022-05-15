//
// Created by Tomse Cosmin on 07.05.2022.
//
#include "bani.h"
#include "repoBani.h"
#include <stack>
#ifndef INC_7_SERVICE_BANI_H
#define INC_7_SERVICE_BANI_H


class BaniService {
private:
    RepoB<Bani> &repoB;
public:
    explicit BaniService(RepoB<Bani> &otherRepositoryB): repoB{otherRepositoryB}{};

    /**
     * destructor
     */
     ~BaniService()=default;



     void addBani(const Bani& p);

     void delBani(unsigned int valoare);

     void updateBani(const Bani& p);

     void removeBani(const Bani& p);

     std::vector<Bani> getAll();

     int getSize();

     Bani getBani(unsigned int valoare);

     std::vector<Bani> rest(unsigned int rest);

     int getQuantity();

     std::vector<int> getArray();

     std::vector<int> sortArray();

    void solve(int s, int index, const int numberOfElements, const int sum, const std::vector<int> set, std::vector<int> &sol)
    {
bool hasSolution;
if (s>sum)
    return;
if (s==sum)
    hasSolution= true;



    }





};
#endif //INC_7_SERVICE_BANI_H
