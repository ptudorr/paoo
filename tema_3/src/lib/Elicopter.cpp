#include "Elicopter.h"
#include <iostream>
#include <cstring>

using namespace std;
using namespace eli;

namespace eli{
    Elicopter::Elicopter(const string& nume_companie, 
        const string& numar_zbor, 
        int viteza_max)
        : nume_companie(nume_companie), numar_zbor(numar_zbor), viteza_max(viteza_max) {}

    void Elicopter::afiseaza_detalii_avion() {
        cout << "Nume companie: " << nume_companie << endl;
        cout << "Numar zbor: " << numar_zbor << endl;
        cout << "Viteza maxima: " << viteza_max << " km/h" << endl;
    }

    void Elicopter::decolare() {
        cout << "Elicopterul a decolat!" << endl;
    }

    void Elicopter::aterizare() {
        cout << "Elicopterul a aterizat!" << endl;
    }
}
