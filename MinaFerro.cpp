#include "MinaFerro.h"
#include "Zona.h"

void MinaFerro::newDay() {
    Edificio::newDay();
    bool TrueFalse = (rand() % 100) < ProbCollap;
    if(TrueFalse){
        cout << "O edificio " << getTipo() << " desabou na Zona " << getZonaRef()->getTipoZona() << endl;
        getZonaRef()->removeEdificio();
    }else if(getZonaRef()->getDay() - getConstrucDay() == 10 && getZonaRef()->getTipoZona() == "pnt") {
        cout << "O edificio " << getTipo() << " afundou na Zona " << getZonaRef()->getTipoZona() << endl;
        getZonaRef()->removeEdificio();
        getZonaRef()->fireAllWorkers();
    }
}

void MinaFerro::produzir() {
    Edificio::produzir();
    if(getZonaRef()->haveMiner() && getZonaRef()->getTipoZona() == "mnt") {
        getZonaRef()->addFerro(4);
    }
    if(getZonaRef()->haveMiner()) {
        getZonaRef()->addFerro(2);
    }
}
