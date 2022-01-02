

#include "Fundicao.h"
#include "Zona.h"


void Fundicao::newDay() {
    Edificio::newDay();
    if(getZonaRef()->getDay() - getConstrucDay() == 10 && getZonaRef()->getTipoZona() == "pnt") {
        cout << "O edificio " << getTipo() << " afundou na Zona " << getZonaRef()->getTipoZona() << endl;
        getZonaRef()->removeEdificio();
        getZonaRef()->fireAllWorkers();
    }
}

void Fundicao::produzir() {
    Edificio::produzir();
    if(getZonaRef()->haveOper()
    && getZonaRef()->getTipoZona() == "mnt"
    && getZonaRef()->getCarvao() >= .5
    && getZonaRef()->getFerro() >= 1.5
    && getZonaRef()->HavemnAround()){

            getZonaRef()->withdrawCarvao(.5);
            getZonaRef()->withdrawFerro(1.5);
            getZonaRef()->addBarraAco(2);

    } else if(getZonaRef()->haveOper()
              && getZonaRef()->getCarvao() >= .5
              && getZonaRef()->getFerro() >= 1.5
              && getZonaRef()->HavemnAround()) {

        getZonaRef()->withdrawCarvao(.5);
        getZonaRef()->withdrawFerro(1.5);
        getZonaRef()->addBarraAco(1);

    } else {
        if(!getZonaRef()->haveOper()) {
            cout << "A Fundicao nao tem nenhum operario a trabalhar." << endl;
        } else if(!getZonaRef()->HavemnAround()){
            cout << "A Fundicao nao esta adjacente a uma mnC e mnF ou a uma elec." << endl;
        }  else if(getZonaRef()->getCarvao() < .5 || getZonaRef()->getFerro() < 1.5) {
            cout << "A Fundicao nao tem a quantidade de materia suficiente." << endl;
        }
    }
}

