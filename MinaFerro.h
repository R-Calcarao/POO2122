//
// Created by ACER on 23/12/2021.
//

#ifndef PRATICOTRABALHO_MINAFERRO_H
#define PRATICOTRABALHO_MINAFERRO_H

#include "Edificio.h"


class MinaFerro : public Edificio{

    const float ProbCollap = .1;
public:
    MinaFerro() : Edificio("mnF",15/*e uma viga*/,100/*kg de ferro*/){};
};


#endif //PRATICOTRABALHO_MINAFERRO_H
