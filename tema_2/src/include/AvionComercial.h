#pragma once
#include "Avion.h"

using namespace std;
using namespace av;

namespace avcom {
    class AvionComercial : public Avion {
    private:
        int capacitate_pasageri;

    public:
        AvionComercial(const string& nume_companie, 
            const string& model, 
            const char* serie,
            int viteza_max,
            int capacitate_pasageri);

        AvionComercial& operator=(const AvionComercial& other); 
        AvionComercial& operator=(AvionComercial&& other);
        
        void calculeazaConsumCombustibil() override;
        void afiseaza_detalii_avion() override;
    };
}