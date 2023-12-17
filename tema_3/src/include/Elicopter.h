#pragma once
#include "IAparatZbor.h"
#include <string>

using namespace std;
using namespace iapzb;

namespace eli{
    class Elicopter:IAparatZbor{
    private:
        string nume_companie;
        string numar_zbor;
        int viteza_max;

    public:
        Elicopter(const string& nume_companie, 
            const string& numar_zbor, 
            int viteza_max);

        void afiseaza_detalii_avion();
        void decolare() override;
        void aterizare() override;
    };
}