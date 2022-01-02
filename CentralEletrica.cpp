

#include "CentralEletrica.h"
#include "Zona.h"

void CentralEletrica::newDay() {
    Edificio::newDay();
    if(getZonaRef()->getDay() - getConstrucDay() == 10 && getZonaRef()->getTipoZona() == "pnt") {
        cout << "O edificio " << getTipo() << " afundou na Zona " << getZonaRef()->getTipoZona() << endl;
        getZonaRef()->removeEdificio();
        getZonaRef()->fireAllWorkers();
    }
}

void CentralEletrica::produzir() {
    Edificio::produzir();
    if(getZonaRef()->haveOper()
    && getZonaRef()->getTipoZona() == "mnt"
    && getZonaRef()->getMadeira() >= 1
    && getZonaRef()->HaveflrAround()) {

        getZonaRef()->withdrawMadeira(1);
        getZonaRef()->addCarvao(2);

    } else if(getZonaRef()->haveOper()
              && getZonaRef()->getMadeira() >= 1
              && getZonaRef()->HaveflrAround()) {

        getZonaRef()->withdrawMadeira(1);
        getZonaRef()->addCarvao(1);
    } else {
        if(!getZonaRef()->haveOper()) {
            cout << "A Central Eletrica nao tem nenhum operario a trabalhar." << endl;
        } else if(getZonaRef()->getMadeira() < 1) {
            cout << "A Central Eletrica nao tem materia suficiente." << endl;
        } else if(!getZonaRef()->HaveflrAround()) {
            cout << "A Centrel nao esta adjacente a nenhuma floresta ou a floresta nao produziu madeira." << endl;
        }
    }
}
