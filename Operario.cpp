//
// Created by ACER on 23/12/2021.
//

#include "Operario.h"
#include "Zona.h"

void Operario::newWorkDay() {
    if(giveZonaRef()->getTipoZona()=="mnt" && getContractDay()-10 >= 0){
        int p = probDemi + (probDemi*0.05);
        bool TrueFalse = (rand() % 100) < p;
        if(TrueFalse){
            cout << "Vou me embora da zona: " << giveZonaRef()->getTipoZona() << ", sou o " << getTipo() << " de id: " <<
            getId() << " . Adeus!!" << endl;
            giveZonaRef()->fireWorker(getId());
        }

    } else if(getContractDay()-10 >= 0){
        bool TrueFalse = (rand() % 100) < probDemi;
        if(TrueFalse){
            cout << "Vou me embora da zona: " << giveZonaRef()->getTipoZona() << ", sou o " << getTipo() << " de id: " <<
                 getId() << " . Adeus!!" << endl;
            giveZonaRef()->fireWorker(getId());
        }
    }
}