#include "AvionCargo.h"
#include <iostream>

using namespace std;
using namespace avcgo;

namespace avcgo {
    AvionCargo::AvionCargo(const string& nume_companie, 
        const string& model, 
        const char* serie,
        int viteza_max,
        int capacitate_marfuri)
        : Avion(nume_companie, model, serie, viteza_max), capacitate_marfuri(capacitate_marfuri) {}

    // =Operator for Copy
    AvionCargo& AvionCargo::operator=(const AvionCargo& other) {
        if (this == &other) {
            return *this;
        }

        delete[] serie;

        nume_companie = other.nume_companie;
        model = other.model;
        viteza_max = other.viteza_max;
        capacitate_marfuri = other.capacitate_marfuri;

        if (other.serie) {
            serie = new char[strlen(other.serie) + 1];
            strcpy(serie, other.serie);
        }

        return *this;
    }

    // =Operator for Move
    AvionCargo& AvionCargo::operator=(AvionCargo&& other) {
        if (this == &other) {
            return *this;
        }

        delete[] serie;

        nume_companie = other.nume_companie;
        model = other.model;
        viteza_max = other.viteza_max;
        capacitate_marfuri = other.capacitate_marfuri;

        if (other.serie) {
            serie = other.serie;
            other.serie = nullptr;
        }

        return *this;
    }

    void AvionCargo::calculeazaConsumCombustibil(){
        cout << "Avionul cargo va consuma " << capacitate_marfuri / 10 << " gal/mil." << endl;
    }
        
    void AvionCargo::afiseaza_detalii_avion() {
        Avion::afiseaza_detalii_avion();
        cout << "Capacitate marfuri in tone: " << capacitate_marfuri << endl;
    }
}