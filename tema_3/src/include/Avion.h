#pragma once
#include "IAparatZbor.h"
#include <string>
#include <semaphore>

using namespace std;
using namespace iapzb;

namespace av{
    class Avion: public IAparatZbor {

    static std::counting_semaphore<2> gatesSemaphore;
        
    static int noOfThreads;
    static string gates[2];
    
    private:
        static void* alocate_gate(void*);

    protected:
        string nume_companie;
        string numar_zbor;
        char* serie;
        int viteza_max;

    public:
        Avion(const string& nume_companie, 
            const string& numar_zbor, 
            const char* serie,
            int viteza_max);
        ~Avion();
        Avion(const Avion& other);
        Avion(Avion&& other);
        void schimbaSeria(const char* seria_noua);

        virtual void afiseaza_detalii_avion();
        virtual void calculeazaConsumCombustibil() = 0;

        Avion& operator=(const Avion& other); 
        Avion& operator=(Avion&& other); 

        void decolare() override;
        void aterizare() override;
        
        static int getNumberOfThreads();
    };
}