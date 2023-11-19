#include "AvionCargo.h"
#include "AvionComercial.h"
#include "Elicopter.h"
#include <iostream>

using namespace avcgo;
using namespace avcom;
using namespace eli;

using namespace std;

int main() {

    AvionCargo avionCargo("DHL", "Boeing B747", "msn212", 300, 1000);
    AvionComercial avionComercial("Lufthansa", "Airbus A380", "mln333", 400, 455);
    Elicopter elicopter("LKM", "tgv245", 320);

    AvionComercial avionComercial_2("Emirates", "Airbus A320", "tpn000", 300, 250);
    AvionCargo avionCargo_2("FedEx", "Boeing B747", "mtcn112", 300, 800);

    avionCargo.afiseaza_detalii_avion();
    avionCargo.calculeazaConsumCombustibil();
    cout << endl;

    avionCargo = move(avionCargo_2);
    avionCargo_2.afiseaza_detalii_avion();
    cout << endl;

    avionComercial.afiseaza_detalii_avion();
    avionComercial.calculeazaConsumCombustibil();
    cout << endl;

    avionComercial = avionComercial_2;
    avionComercial_2.afiseaza_detalii_avion();
    cout << endl;

    elicopter.afiseaza_detalii_avion();
    elicopter.decolare();
    elicopter.aterizare();
    
    return 0;
}

