#ifndef PRATICOTRABALHO_MONTANHA_H
#define PRATICOTRABALHO_MONTANHA_H

#include "Zona.h"

class Montanha : public Zona {

    const string tipo;
public:
    Montanha() : Zona("mnt"){};

    void newDay() override {
        Zona::newDay();
        addFerro(NumbWorkers()*.1);
    }

};

#endif //PRATICOTRABALHO_MONTANHA_H
