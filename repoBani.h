//
// Created by Tomse Cosmin on 07.05.2022.
//

#ifndef INC_7_REPOBANI_H
#define INC_7_REPOBANI_H

#include <vector>
#include <stdexcept>
#include "bani.h"
#include <fstream>
#include <cstring>
#include <sstream>

template<class T>
class RepoB {
private:
    std::vector<T> entities;
public:
    void add(T t);

    int getPosition(unsigned int valaore);

    void update(T t);

    void del(unsigned int valaore);

    void remove(T t);

    std::vector<T> getAll(T);

    int getSize() { return this->entities.size(); };

    T get(unsigned int valaore);

    void readFromFileB(const std::string& filename);

    void saveToFileB(const std::string& filename);
};

template<class T>
void RepoB<T>::add(T t) {
    int k, v;
    v = t.getValaore();
    k = this->getPosition(v);
    if (k == -1) { this->entities.push_back(t); }
    else {
        this->entities[k].setCantitate(this->entities[k].getCantitate() + t.getCantitate());
    }
    this->saveToFileB("repoB.txt");
}


template<class T>
T RepoB<T>::get(unsigned int valoare) {
    for (auto entity: this->entities) {
        if (entity.getValaore() == valoare) {
            return entity;
        }
    }
    throw std::out_of_range("Nici o entitate cu valaorea cautata");
}

template<class T>
std::vector<T> RepoB<T>::getAll(T) {
    return this->entities;
}


template<class T>
int RepoB<T>::getPosition(unsigned int valaore) {
    int index = 0;
    for (const auto &it: this->entities) {
        if (it.getValaore() == valaore) {
            return index;
        }
        index++;
    }
    return -1;
}

template<class T>
void RepoB<T>::update(T t) {
    for (auto &oldentity: this->entities) {
        if (oldentity.getValaore() == t.getValaore()) {
            oldentity = t;
        }
    }
    this->saveToFileB("repoB.txt");
}

template<class T>
void RepoB<T>::del(unsigned int valaore) {
    if (getPosition(valaore) != -1) {
        this->entities.erase(this->entities.begin() + getPosition(valaore));
    }
    this->saveToFileB("repoB.txt");
}

template<class T>
void RepoB<T>::remove(T t) {
    unsigned int k, v;
    v = t.getValaore();
    k = this->getPosition(v);
    if (k >= 0)
        if (this->entities[k].getCantitate() >= t.getCantitate()) {
            this->entities[k].setCantitate(this->entities[k].getCantitate() - t.getCantitate());
        }
    this->saveToFileB("repoB.txt");
}

template<class T>
void RepoB<T>::readFromFileB(const std::string &filename) {
    std::ifstream f(filename);
    std::string line;

    std::getline(f, line);
    while (!line.empty()) {
        Bani bani;
        std::vector<std::string> tokens;
        std::stringstream check(line);
        std::string intermediate;

        while (std::getline(check, intermediate, ',')) {
            tokens.push_back(intermediate);
        }

        bani.setValoare(stoi(tokens[0]));
        bani.setCantitate(stoi(tokens[1]));

        this->entities.push_back(bani);

        std::getline(f, line);
    }
}

template<class T>
void RepoB<T>::saveToFileB(const std::string &filename) {
    std::ofstream g(filename);
    for (auto& entity: this->entities) {
        g << entity.getValaore() << "," <<  entity.getCantitate() << '\n';
    }
    g.close();
}



#endif //INC_7_REPOBANI_H
