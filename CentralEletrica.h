

#ifndef PRATICOTRABALHO_CENTRALELETRICA_H
#define PRATICOTRABALHO_CENTRALELETRICA_H

#include "Edificio.h"



class CentralEletrica : public Edificio{

public:
    CentralEletrica(int day) : Edificio("elec",0,100/*kg de carvao*/,day){}

    void newDay() override;

    void produzir() override;
};


#endif //PRATICOTRABALHO_CENTRALELETRICA_H
