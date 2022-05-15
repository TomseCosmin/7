//
// Created by Tomse Cosmin on 19.04.2022.
//

#include <string>
#ifndef INC_7_PRODUS_H
#define INC_7_PRODUS_H

class Produs{
private:
    unsigned int cod;
    std::string nume;
    unsigned int pret;
public:
    /**
     * constructor def
     */
    Produs();

    /**
     * constructor explicit
     */
    explicit Produs(unsigned int cod, std::string nume, unsigned int pret);

    /**
     * constructor de copiere
     */
     Produs(const Produs& other);

     /**
      * destructor
      */
      ~Produs();

      /**
       * setter cod
       */
       void setCod(unsigned int cod);

       /**
        * setter nume
        */
        void setNume(std::string nume);

        /**
         * setter pret
         */
         void setPret(unsigned int pret);

         /**
          * getter cod
          */
         unsigned int getCod() const {return this->cod;};

         /**
          * getter nume
          */
         std::string getNume() const{return this->nume;};

         /**
          * getter pret
          */
         unsigned int getPret() const {return this->pret;};


};
#endif //INC_7_PRODUS_H
