#include "Avion.h"
#include <iostream>
#include <cstring>

using namespace std;
using namespace av;

namespace av{
    Avion::Avion(const string& nume_companie, 
        const string& model, 
        const char* serie,
        int viteza_max)
        : nume_companie(nume_companie), model(model), viteza_max(viteza_max) {
        
        this->serie = new char[strlen(serie) + 1];
        strcpy(this->serie, serie);
    }

    // Destructor
    Avion::~Avion() {
        delete[] serie;
    }

    // Copy Constructor - LValue
    Avion::Avion(const Avion& other)
        : nume_companie(other.nume_companie), model(other.model), viteza_max(other.viteza_max){
        
        this->serie = new char[strlen(other.serie) + 1];
        strcpy(this->serie, other.serie);
    }

    // Move Constructor - RValue
    Avion::Avion(Avion&& other)
        : nume_companie(move(other.nume_companie)), model(move(other.model)), viteza_max(other.viteza_max){
        
        serie = other.serie;
        other.serie = nullptr;
    }

    void Avion::schimbaSeria(const char* seria_noua) {
        if (seria_noua) {
            if (serie) {
                delete[] serie;
            }

            serie = new char[strlen(seria_noua) + 1];
            strcpy(serie, seria_noua); 
        }
    }

    /// Tema 2 ///
    void Avion::afiseaza_detalii_avion(){
        cout << "Nume companie: " << nume_companie << endl;
        cout << "Model: " << model << endl;
        if (serie != nullptr){
            cout << "Serie: " << serie << endl;
        }
        cout << "Viteza maxima: " << viteza_max << " km/h" << endl;
    }

    // =Operator for Copy
    Avion& Avion::operator=(const Avion& other) {
        if (this == &other) {
            return *this;
        }

        delete[] serie;

        nume_companie = other.nume_companie;
        model = other.model;
        viteza_max = other.viteza_max;

        if (other.serie) {
            serie = new char[strlen(other.serie) + 1];
            strcpy(serie, other.serie);
        }

        return *this;
    }

    // =Operator for Move
    Avion& Avion::operator=(Avion&& other) {
        if (this == &other) {
            return *this;
        }

        delete[] serie;

        nume_companie = other.nume_companie;
        model = other.model;
        viteza_max = other.viteza_max;

        if (other.serie) {
            serie = other.serie;
            other.serie = nullptr;
        }

        return *this;
    }

    // Interface
    void Avion::decolare(){
        cout << "Avionul a decolat!" << endl;
    }

    void Avion::aterizare(){
        cout << "Avionul a aterizat!" << endl;
    }
}
