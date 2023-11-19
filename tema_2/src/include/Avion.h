#pragma once
#include "IAparatZbor.h"
#include <string>

using namespace std;
using namespace iapzb;

namespace av{
    class Avion: public IAparatZbor {
    protected:
        string nume_companie;
        string model;
        char* serie;
        int viteza_max;

    public:
        Avion(const string& nume_companie, 
            const string& model, 
            const char* serie,
            int viteza_max);
        ~Avion();
        Avion(const Avion& other);
        Avion(Avion&& other);
        void schimbaSeria(const char* seria_noua);

        virtual void afiseaza_detalii_avion();
        virtual void calculeazaConsumCombustibil() = 0;

        Avion& operator=(const Avion& other); 
        Avion& operator=(Avion&& other); 

        void decolare() override;
        void aterizare() override;
    };
}