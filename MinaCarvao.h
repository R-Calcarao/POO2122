//
// Created by ACER on 23/12/2021.
//

#ifndef PRATICOTRABALHO_MINACARVAO_H
#define PRATICOTRABALHO_MINACARVAO_H

#include "Edificio.h"


class MinaCarvao : public Edificio{

    const float ProbCollap = .1;
public:
    MinaCarvao() : Edificio("mnC",10/*e uma viga*/,100/*de Carvao*/){

    };
};


#endif //PRATICOTRABALHO_MINACARVAO_H
