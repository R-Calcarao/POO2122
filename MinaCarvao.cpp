#include "MinaCarvao.h"
#include "Zona.h"

void MinaCarvao::newDay() {
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

void MinaCarvao::produzir() {
    Edificio::produzir();
    if(getZonaRef()->haveMiner() && getZonaRef()->getTipoZona() == "mnt") {
        getZonaRef()->addCarvao(4);
    }
    if(getZonaRef()->haveMiner()) {
        getZonaRef()->addCarvao(2);
    }
}
