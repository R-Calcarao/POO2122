

#ifndef PRATICOTRABALHO_FLORESTA_H
#define PRATICOTRABALHO_FLORESTA_H

#include "Zona.h"
#include <time.h>

class Floresta : public Zona {
    const string tipo;
    int N_arvores;
    int Madeira=0;//É produzida por Lenhadores
    int Cap_Max=100;
    bool produce = false;
    bool aux = false;
public:

    Floresta(int linha,int coluna) : Zona("flr",linha,coluna){
        srand(time(0));
        N_arvores = (rand()%21)+20;
    };

    int getNumArvores() const{
        return N_arvores;
    }

    bool HaveProduceThisDay() override{
        Zona::HaveflrAround();
        return produce;
    }

    void newDay() override {
        Zona::newDay();
        if(aux) {
            aux = false;
            produce = false;
        }
        if(getDay()%2 == 0 && N_arvores < Cap_Max && getNumEdificios() == 0) {//Só crescem arvores se n existirem edi.
            N_arvores++;
        } else { //Se existirem edificios morre uma arvore por cada dia que passa
            N_arvores--;
        }
        if(N_arvores > Cap_Max){ //Só para ter certeza que o limite n arvores n é passado
            while(N_arvores > Cap_Max) {
                N_arvores--;
            }
        }
        if(N_arvores > 0){
            addMadeira((getNumbLen()-getNumbLenResting())*1);
            if(getNumbLen()-getNumbLenResting()*1 > 0){
                produce = true;
                aux = true;
            }
        }
    }

    string getAsString() override{
        ostringstream oss;
        oss << Zona::getAsString();
        oss << "Numero de Arvores: " << getNumArvores() << endl;
        oss << endl;
        return oss.str();
    }

};


#endif //PRATICOTRABALHO_FLORESTA_H
