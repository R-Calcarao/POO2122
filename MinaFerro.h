#ifndef PRATICOTRABALHO_MINAFERRO_H
#define PRATICOTRABALHO_MINAFERRO_H

#include "Edificio.h"


class MinaFerro : public Edificio{

     float ProbCollap = 15;
public:
    MinaFerro(int day) : Edificio("mnF",15/*e uma viga*/,100/*kg de ferro*/, day){};

    void newDay() override;

    void produzir() override;


};
