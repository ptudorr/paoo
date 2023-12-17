#include <iostream>
#include "AvionComercial.h"

using namespace std;
using namespace avcom;

namespace avcom {
    AvionComercial::AvionComercial(const string& nume_companie, 
        const string& numar_zbor, 
        const char* serie,
        int viteza_max,
        int capacitate_pasageri)
        : Avion(nume_companie, numar_zbor, serie, viteza_max), capacitate_pasageri(capacitate_pasageri) {}

    // =Operator for Copy
    AvionComercial& AvionComercial::operator=(const AvionComercial& other) {
        if (this == &other) {
            return *this;
        }

        delete[] serie;

        nume_companie = other.nume_companie;
        numar_zbor = other.numar_zbor;
        viteza_max = other.viteza_max;
        capacitate_pasageri = other.capacitate_pasageri;

        if (other.serie) {
            serie = new char[strlen(other.serie) + 1];
            strcpy(serie, other.serie);
        }

        return *this;
    }

    // =Operator for Move
    AvionComercial& AvionComercial::operator=(AvionComercial&& other) {
        if (this == &other) {
            return *this;
        }

        delete[] serie;

        nume_companie = other.nume_companie;
        numar_zbor = other.numar_zbor;
        viteza_max = other.viteza_max;
        capacitate_pasageri = other.capacitate_pasageri;

        if (other.serie) {
            serie = other.serie;
            other.serie = nullptr;
        }

        return *this;
    }

    void AvionComercial::calculeazaConsumCombustibil(){
        cout << "Avionul comercial va consuma " << capacitate_pasageri / 10 << " gal/mil." << endl;
    }
        
    void AvionComercial::afiseaza_detalii_avion() {
        Avion::afiseaza_detalii_avion();
        cout << "Capacitate pasageri: " << capacitate_pasageri << endl;
    }

}
