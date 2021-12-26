//
// Created by ACER on 23/12/2021.
//

#ifndef PRATICOTRABALHO_EDIFICIO_H
#define PRATICOTRABALHO_EDIFICIO_H

#include <string>

using namespace std;

class Edificio {

    const string tipo;
    int lvlPrice;
    int capMax;
public:
    Edificio(const string tipo, const int lvlPrice, int capMax) : tipo(tipo),lvlPrice(lvlPrice),capMax(capMax){}


};


#endif //PRATICOTRABALHO_EDIFICIO_H
