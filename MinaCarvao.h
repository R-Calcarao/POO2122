#ifndef PRATICOTRABALHO_MINACARVAO_H
#define PRATICOTRABALHO_MINACARVAO_H

#include "Edificio.h"


class MinaCarvao : public Edificio{

     float ProbCollap = 10;
public:
    MinaCarvao(int day) : Edificio("mnC",10/*e uma viga*/,100/*de Carvao*/,day){}

    void newDay() override;

    void produzir() override;


};


#endif //PRATICOTRABALHO_MINACARVAO_H
