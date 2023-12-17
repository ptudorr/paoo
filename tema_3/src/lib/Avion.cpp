#include "Avion.h"
#include "AvionComercial.h"
#include "AvionCargo.h"
#include <iostream>
#include <cstring>
#include <pthread.h>
#include <unistd.h>
#include <semaphore>

using namespace std;
using namespace av;
using namespace avcom;
using namespace avcgo;

std::counting_semaphore<2> Avion::gatesSemaphore(2);
std::mutex noOfThreadsMutex;

string Avion::gates[2];
int Avion::noOfThreads;

namespace av{
    Avion::Avion(const string& nume_companie, 
        const string& numar_zbor, 
        const char* serie,
        int viteza_max)
        : nume_companie(nume_companie), numar_zbor(numar_zbor), viteza_max(viteza_max) {
        
        this->serie = new char[strlen(serie) + 1];
        strcpy(this->serie, serie);
    }

    // Destructor
    Avion::~Avion() {
        cout << "Se apeleaza deconstructorul!" << endl;
        delete[] serie;
    }

    // Copy Constructor - LValue
    Avion::Avion(const Avion& other)
        : nume_companie(other.nume_companie), numar_zbor(other.numar_zbor), viteza_max(other.viteza_max){
        
        this->serie = new char[strlen(other.serie) + 1];
        strcpy(this->serie, other.serie);
    }

    // Move Constructor - RValue
    Avion::Avion(Avion&& other)
        : nume_companie(move(other.nume_companie)), numar_zbor(move(other.numar_zbor)), viteza_max(other.viteza_max){
        
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
        cout << "numar_zbor: " << numar_zbor << endl;
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
        numar_zbor = other.numar_zbor;
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
        numar_zbor = other.numar_zbor;
        viteza_max = other.viteza_max;

        if (other.serie) {
            serie = other.serie;
            other.serie = nullptr;
        }

        return *this;
    }

    // Interface
    void Avion::decolare(){
        cout << "Zborul " << this->numar_zbor << " a decolat!" << endl;
    }

    void Avion::aterizare(){
        cout << "Zborul " << this->numar_zbor << " a aterizat!" << endl;
        pthread_t thrd;

        noOfThreadsMutex.lock();
        noOfThreads++;
        noOfThreadsMutex.unlock();

        string cautare = "Se cauta un terminal pentru cursa " + this->numar_zbor + ".\n";
    
        pthread_create(&thrd, NULL, alocate_gate, this);
        pthread_detach(thrd);

    }

    void* Avion::alocate_gate(void* arg){
        gatesSemaphore.acquire();

        Avion* avion = static_cast<Avion*>(arg);
        // gatesMutex.lock();

        int i;

        for(i = 0; i <= 9; i++) {
            if(gates[i].empty()) { 
                gates[i] = avion->numar_zbor;
                string terminal = "Pentru cursa " + avion->numar_zbor + " a fost alocat terminalul " + to_string(i) + ".\n";
                cout << terminal;
                break;
            }
        }

        string zbor = "Avionul este in pregatiri pentru urmatorul zbor.\n";
        cout<< zbor;
        sleep(2);
        gates[i].clear();
        avion->decolare();
        cout << endl;
        gatesSemaphore.release();

        noOfThreadsMutex.lock();
        noOfThreads--;
        noOfThreadsMutex.unlock();

        return NULL;
    }

    int Avion::getNumberOfThreads(){
        noOfThreadsMutex.lock();
        int nmbr = noOfThreads;
        noOfThreadsMutex.unlock();

        return nmbr;
    }

}
