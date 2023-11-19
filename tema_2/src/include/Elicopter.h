#pragma once
#include "IAparatZbor.h"
#include <string>

using namespace std;
using namespace iapzb;

namespace eli{
    class Elicopter:IAparatZbor{
    private:
        string nume_companie;
        string model;
        int viteza_max;

    public:
        Elicopter(const string& nume_companie, 
            const string& model, 
            int viteza_max);

        void afiseaza_detalii_avion();
        void decolare() override;
        void aterizare() override;
    };
}