//
// Created by ACER on 23/12/2021.
//

#ifndef PRATICOTRABALHO_CENTRALELETRICA_H
#define PRATICOTRABALHO_CENTRALELETRICA_H

#include "Edificio.h"



class CentralEletrica : public Edificio{

public:
    CentralEletrica() : Edificio("elec",0,100/*kg de carvao*/){

    };
};


#endif //PRATICOTRABALHO_CENTRALELETRICA_H
