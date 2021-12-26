//
// Created by ACER on 23/12/2021.
//

#ifndef PRATICOTRABALHO_PASTAGEM_H
#define PRATICOTRABALHO_PASTAGEM_H

#include <cstring>
#include "Zona.h"


class Pastagem : public Zona{

    const string tipo;
public:
    Pastagem() : Zona("pas"){};

};


#endif //PRATICOTRABALHO_PASTAGEM_H
