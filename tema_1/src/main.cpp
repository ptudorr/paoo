#include "avion.h"
#include <iostream>

int main() {

    Avion avion1("Lufthansa", "Airbus A380", 850, "msn212", 300);
    Avion avion2("Etihad Airways", "Boeing B747", 800, "msn312", 250);
    
    Avion avion1_copy = avion1;
    // Avion avion1_copy(avion1); // egal cu mai sus

    Avion avion1_move(std::move(avion1));
        
    // Avionul initial nu va mai avea elementele alocate dinamic, deoarece move constructorul le referentiaza la null.
    avion1.afiseaza_detalii_avion();
    std::cout << std::endl;

    std::cout << "Luftahnsa creat de copy constructor:" << std::endl;
    avion1_copy.afiseaza_detalii_avion();
    std::cout << std::endl;

    std::cout << "Lufthansa creat de copy constructor a carui serie a fost modificata:" << std::endl;
    avion1_copy.schimbaSeria("000");
    avion1_copy.afiseaza_detalii_avion();
    std::cout << std::endl;

    std::cout << "Lufthansa creat de move constructor:" << std::endl;
    avion1_move.afiseaza_detalii_avion();
    std::cout << std::endl;

    avion2.afiseaza_detalii_avion();
    std::cout << std::endl;

    Avion avion2_move(std::move(avion2)); 

    std::cout << "Etihad creat de move constructor dar cu seria modificata:" << std::endl;
    avion2_move.schimbaSeria("111");   
    avion2_move.afiseaza_detalii_avion();

    return 0;
}