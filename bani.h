//
// Created by Tomse Cosmin on 07.05.2022.
//

#ifndef INC_7_BANI_H
#define INC_7_BANI_H
class Bani{
private:
    unsigned int valoare;
    unsigned int cantitate;
public:
    /**
     * constructor def
     */
     Bani();

     /**
      * constructor explicit
      */
      explicit Bani(unsigned int valoare, unsigned int cantitate);

      /**
       * constructor de copiere
       */
       Bani(const Bani& other);

       /**
        * destructor
        */
        ~Bani();

        /**
         * setter valoare
         */
         void setValoare(unsigned int valaore);

         /**
          * setter cantitate
          */
          void setCantitate(unsigned int cantitate);

          /**
           * getter valoare
           */
           unsigned int getValaore() const {return this->valoare;};

           /**
            * getter cantitate
            */
           unsigned int getCantitate() const {return this->cantitate;};

};
#endif //INC_7_BANI_H
