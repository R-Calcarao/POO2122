//
// Created by ACER on 23/12/2021.
//

#ifndef PRATICOTRABALHO_BATERIA_H
#define PRATICOTRABALHO_BATERIA_H

#include "Edificio.h"


class Bateria : public Edificio{

public:
    Bateria() : Edificio("bat",5,100/*KWh*/){

    };

};


#endif //PRATICOTRABALHO_BATERIA_H
