//
// Created by ACER on 23/12/2021.
//

#ifndef PRATICOTRABALHO_FLORESTA_H
#define PRATICOTRABALHO_FLORESTA_H

#include "Zona.h"
#include <time.h>

class Floresta : public Zona {
    const string tipo;
    int N_arvores;
    int Madeira=0;//É produzida por Lenhadores
public:

    Floresta() : Zona("flr"){
        srand(time(0));
        N_arvores = (rand()%21)+20;
    };

    int getNumArvores() const{
        return N_arvores;
    }

};


#endif //PRATICOTRABALHO_FLORESTA_H
