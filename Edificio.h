#ifndef PRATICOTRABALHO_EDIFICIO_H
#define PRATICOTRABALHO_EDIFICIO_H

#include <string>
#include <sstream>

using namespace std;

class Recursos;
class Zona;

class Edificio {

    const string tipo;
    int lvlPrice;
    int capMax;
    int construcDay;
    Recursos* recursos;
    Zona* zona;
    bool ligado=false;


public:
    Edificio(const string tipo, const int lvlPrice, int capMax, int construcDay) : tipo(tipo),lvlPrice(lvlPrice),
                                                                                   capMax(capMax), construcDay(construcDay){}

    void pointToRecursos(Recursos* abc){
        recursos = abc;
    }

    string getTipo() const{
        return tipo;
    }

    int getConstrucDay() const{
        return construcDay;
    }

    void pointToZona(Zona* abc){
        zona = abc;
    }

    Zona* getZonaRef() const{
        return zona;
    }

    string flag();

     virtual void newDay(){}

     virtual void produzir(){}

};


#endif //PRATICOTRABALHO_EDIFICIO_H
