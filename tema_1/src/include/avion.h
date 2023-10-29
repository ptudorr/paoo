#pragma once

#include <string>

class Avion {
private:
    std::string nume_companie;
    std::string model;
    int capacitate;
    char* serie;
    int viteza_max;

public:
    Avion(const std::string& nume_companie, 
        const std::string& model, 
        int capacitate, 
        const char* serie,
        int viteza_max);
    ~Avion();
    Avion(const Avion& other);
    Avion(Avion&& other);
    void afiseaza_detalii_avion();
    void schimbaSeria(const char* seria_noua);
};