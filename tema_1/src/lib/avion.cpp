#include "avion.h"
#include <iostream>
#include <cstring>

Avion::Avion(const std::string& nume_companie, 
    const std::string& model, 
    int capacitate, 
    const char* serie,
    int viteza_max)
    : nume_companie(nume_companie), model(model), capacitate(capacitate), viteza_max(viteza_max) {
    
    this->serie = new char[strlen(serie) + 1];
    strcpy(this->serie, serie);
}

// Destructor
Avion::~Avion() {
    delete[] serie;
}

// Copy Constructor - L-value
Avion::Avion(const Avion& other)
    : nume_companie(other.nume_companie), model(other.model), capacitate(other.capacitate), viteza_max(other.viteza_max){
    
    this->serie = new char[strlen(other.serie) + 1];
    strcpy(this->serie, other.serie);
}

// Move Constructor - R-value reference
Avion::Avion(Avion&& other)
    : nume_companie(std::move(other.nume_companie)), model(std::move(other.model)), capacitate(other.capacitate), viteza_max(other.viteza_max){
    
    other.serie = nullptr;
}

void Avion::afiseaza_detalii_avion() {
    std::cout << "Nume companie: " << nume_companie << std::endl;
    std::cout << "Model: " << model << std::endl;
    std::cout << "Capacitate: " << capacitate << " pasageri" << std::endl;
    if (serie != nullptr){
        std::cout << "Serie: " << serie << std::endl;
    }
    std::cout << "Viteza maxima: " << viteza_max << " km/h" << std::endl;
}
