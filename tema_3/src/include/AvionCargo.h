#pragma once
#include "Avion.h"

using namespace std;
using namespace av;

namespace avcgo {
    class AvionCargo : public Avion {
    private:
        int capacitate_marfuri;

    public:
        AvionCargo(const string& nume_companie, 
            const string& numar_zbor, 
            const char* serie,
            int viteza_max,
            int capacitate_marfuri);

        AvionCargo& operator=(const AvionCargo& other); 
        AvionCargo& operator=(AvionCargo&& other); 
        
        void calculeazaConsumCombustibil() override;
        void afiseaza_detalii_avion() override;
    };
}
