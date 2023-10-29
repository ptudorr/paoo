#include "avion.h"
#include <iostream>

int main() {


    Avion avion1("Lufthansa", "Airbus A380", 853, "msn212", 300);
    Avion avion1_copy = avion1;
    // // Avion avion1_copy(avion1); // egal cu mai sus

    Avion avion1_move(std::move(avion1)); 
        
    avion1.afiseaza_detalii_avion();
    std::cout << std::endl;

    std::cout << "Avionul dupa copy constructor:" << std::endl;
    avion1_copy.afiseaza_detalii_avion();
    std::cout << std::endl;

    std::cout << "Avionul după move constructor:" << std::endl;
    avion1_move.afiseaza_detalii_avion();

    return 0;
}