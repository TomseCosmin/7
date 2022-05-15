//
// Created by Tomse Cosmin on 07.05.2022.
//

#include "Service bani.h"
#include "bani.h"


void BaniService::addBani(const Bani &p) {
    this->repoB.add(p);

}

void BaniService::delBani(unsigned int valoare) {
    this->repoB.del(valoare);
}

void BaniService::updateBani(const Bani &p) {
    this->repoB.update(p);
}

void BaniService::removeBani(const Bani &p) {
    this->repoB.remove(p);
    if (this->repoB.get(p.getValaore()).getCantitate() == 0)
    {
        this->repoB.del(p.getValaore());
    }
}

std::vector<Bani> BaniService::getAll() {
    Bani bani;
    std::vector<Bani> clean;
    clean = this->repoB.getAll(bani);
    for (int i=0; i<getSize();i++)
    {
        if (clean[i].getCantitate()==0)
            delBani(clean[i].getValaore());}
            /*return this->repoB.getAll(bani);*/
    return clean;
}

int BaniService::getSize() {
    return this->repoB.getSize();
}

Bani BaniService::getBani(unsigned int valoare) {
    return this->repoB.get(valoare);
}

std::vector<Bani> BaniService::rest(unsigned int rest) {
    int numberOfElements = this->getQuantity();
    int sum = rest;
    int i = 0;
    int start = -1, finish;
    std::vector<int> set = this->sortArray();
    int hasSolution = -1;
    int index;
    int s = 0;
    RepoB<Bani> sol;
    std::vector<int> scade;
    Bani banii;
    while (hasSolution == -1) {
        while (set[i] > rest)
            i++;
        index = i;
        while (index < numberOfElements && hasSolution == -1) {
            s = 0;
            for (int j = index; j < numberOfElements; j++) {
                s = s + set[j];
                if (s == sum) {
                    start = index;
                    finish = j;
                    hasSolution = 1;
                    break;
                }
                if (s > sum)
                {
                    s = s - set[j];
                    scade.push_back(set[j]);
                }

            }
            index++;
        }
        if (start == -1) {
            hasSolution = 0;
        }
    }
    if (start != -1) {
        for (int k = start; k <= finish; k++) {

            banii.setValoare(set[k]);
            banii.setCantitate(1);
            sol.add(banii);
            this->repoB.remove(banii);
        }
        for(int p = 0; p < scade.size(); p++)
        {
             banii.setValoare(scade[p]);
             banii.setCantitate(1);
            sol.remove(banii);
               this->repoB.add(banii);
        }

    }
    return sol.getAll(banii);
}

int BaniService::getQuantity() {
    Bani bani;
    int s = 0;
    for (int i = 0; i < this->repoB.getSize(); i++) {
        s = s + this->repoB.getAll(bani)[i].getCantitate();
    }
    return s;
}

std::vector<int> BaniService::getArray() {
    std::vector<int> array;
    Bani bani;
    int i, j;
    for (int i = 0; i < this->repoB.getSize(); i++) {
        for (int j = 0; j < this->repoB.getAll(bani)[i].getCantitate(); j++) {
            array.push_back(this->repoB.getAll(bani)[i].getValaore());
        }
    }
    return array;
}

std::vector<int> BaniService::sortArray() {
    std::vector<int> sort;
    int size = this->getQuantity();
    sort = this->getArray();
    /* bubbleSort luat de pe net*/
    for (int step = 0; step < size; ++step) {
        for (int i = 0; i < size - step; i++)
            if (sort[i] < sort[i + 1]) {
                int aux = sort[i];
                sort[i] = sort[i + 1];
                sort[i + 1] = aux;
            }
    }
    return sort;
}






