#include "AvionCargo.h"
#include "AvionComercial.h"
#include "Elicopter.h"
#include <iostream>
#include <unistd.h>

using namespace avcgo;
using namespace avcom;
using namespace eli;

using namespace std;

int main() {

    AvionComercial lufthansa("Lufthansa", "LH2435", "mln333", 400, 455);
    AvionCargo dhl("DHL", "DHL4367", "msn212", 300, 1000);
    AvionComercial emirates("Emirates", "EM2856", "emi213", 600, 855);

    lufthansa.decolare();
    dhl.decolare();
    emirates.decolare();

    lufthansa.aterizare();
    dhl.aterizare();
    emirates.aterizare();

    while(Avion::getNumberOfThreads() != 0){
        usleep(1000);
    }

    auto spCom = make_shared<AvionComercial>("Shared Pointer", "---", "---", 0, 0);
    shared_ptr <AvionComercial> sp2Com = spCom; 
    sp2Com.reset();
    spCom.reset(); //expect print deconstructor

    auto spCgo = make_shared<AvionCargo>("Weak Pointer", "---", "---", 0, 0);
    weak_ptr <AvionCargo> wpCgo = spCgo; //nu pot apelqa lucruri
    cout<< "Numarul de shared pointers care pointeaza catre acelasi obiect " << spCgo.use_count() << endl;

    if (auto wpCgo_s = wpCgo.lock()) 
        wpCgo_s->afiseaza_detalii_avion();
	else 									               
        std::cout<< "Obiectul nu mai exista nu mai exista." << endl;
    
    return 0;
}

