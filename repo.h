//
// Created by Tomse Cosmin on 19.04.2022.
//
/*#include "produs.h"
#include <vector>
#include <stdexcept>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;
#ifndef INC_7_REPO_H
#define INC_7_REPO_H
template <class T>
class Repo {
private:
    vector<T> entities;
    string fileName;
public:
    Repo(string);
    virtual void saveToFile()=0;
    virtual void loadFromFile()=0;
    ~Repo();
    void add(T t);
    int getPosition(int cod);
    void remove(int cod);
    void update(T entity);
    std::vector<T> getAll(T);
    T get(int cod);

    int getSize()  {
        return this->entities.size();
    }
};


template<class T>
void Repo<T>::add(T t) {
    this->entities.push_back(t);
    this->saveToFile();
}

template<class T>
std::vector<T> Repo<T>::getAll(T) {
    return this->entities;
}

template<class T>
int Repo<T>::getPosition(int cod) {
    int index = 0;
    for (const auto& it : this->entities) {
        if (it.getCod() == cod ) {
            return index;
        }
        index++;
    }
    return -1;
}

template<class T>
void Repo<T>::remove(int cod) {
    if (getPosition(cod) != -1) {
        this->entities.erase(this->entities.begin() + getPosition(cod));
    }
}

template<class T>
void Repo<T>::update(T entity) {
    for (auto &oldentity : this->entities) {
        if (oldentity.getCod() == entity.getCod()) {
            oldentity = entity;
        }
    }
}

template<class T>
T Repo<T>::get(int cod) {
    for (auto entity : this->entities) {
        if (entity.getCod() == cod) {
            return entity;
        }
    }
    throw std::out_of_range("Nici o entitate cu codul cautat");
}

template<class T>
Repo<T>::Repo(string name) {this->fileName = name ;

}

template<class T>
Repo<T>::~Repo() {

}


#endif //INC_7_REPO_H
*/

//
// Created by Tomse Cosmin on 19.04.2022.
//
#ifndef INC_7_REPO_H
#define INC_7_REPO_H

#include "produs.h"
#include <vector>
#include <stdexcept>
#include <fstream>
#include <cstring>
#include <sstream>

template <class T>
class Repo {
private:
    std::vector<T> entities;
public:
    explicit Repo();
    void add(T t);
    int getPosition(int cod);
    void remove(int cod);
    void update(T entity);
    std::vector<T> getAll(T);
    T get(int cod);
    void saveToFile(const std::string& filename);
    void readFromFile(const std::string& filename);

    int getSize()  {
        return this->entities.size();
    }
};


template<class T>
void Repo<T>::add(T t) {
    this->entities.push_back(t);
    this->saveToFile("repo.txt");
}

template<class T>
std::vector<T> Repo<T>::getAll(T) {
    return this->entities;
}

template<class T>
int Repo<T>::getPosition(int cod) {
    int index = 0;
    for (const auto& it : this->entities) {
        if (it.getCod() == cod ) {
            return index;
        }
        index++;
    }
    return -1;
}

template<class T>
void Repo<T>::remove(int cod) {
    if (getPosition(cod) != -1) {
        this->entities.erase(this->entities.begin() + getPosition(cod));
        this->saveToFile("repo.txt");
    }
    this->saveToFile("repo.txt");
}


template<class T>
void Repo<T>::update(T entity) {
    for (auto &oldentity : this->entities) {
        if (oldentity.getCod() == entity.getCod()) {
            oldentity = entity;
            this->saveToFile("repo.txt");
        }
    }
    this->saveToFile("repo.txt");
}

template<class T>
T Repo<T>::get(int cod) {
    for (auto entity : this->entities) {
        if (entity.getCod() == cod) {
            return entity;
        }
    }
    throw std::out_of_range("Nici o entitate cu codul cautat");
}

template<class T>
void Repo<T>::readFromFile(const std::string& filename) {
    std::ifstream f(filename);
    std::string line;

    std::getline(f, line);
    while (!line.empty()) {
        Produs produs;
        std::vector<std::string> tokens;
        std::stringstream check(line);
        std::string intermediate;

        while (std::getline(check, intermediate, ',')) {
            tokens.push_back(intermediate);
        }

        produs.setCod(stoi(tokens[0]));
        produs.setNume(tokens[1]);
        produs.setPret(stoi(tokens[2]));

        this->entities.push_back(produs);

        std::getline(f, line);
    }
}

template<class T>
void Repo<T>::saveToFile(const std::string& filename) {
    std::ofstream g(filename);
    for (auto& entity: this->entities) {
        g << entity.getCod() << "," << entity.getNume() << "," << entity.getPret() << '\n';
    }
    g.close();
}

template<class T>
Repo<T>::Repo() = default;


#endif //INC_7_REPO_H
