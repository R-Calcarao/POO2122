//
// Created by ACER on 23/12/2021.
//

#ifndef PRATICOTRABALHO_ILHA_H
#define PRATICOTRABALHO_ILHA_H

#include "Zona.h"
#include <vector>

using namespace std;

class Ilha {
    //Deve existir pelo menos uma zona de cada tipo
    //Deve haver um equilibrio na distribuição do número de zonas na ilha
    const int linhas;
    const int colunas;
    vector<vector<Zona*>> ilhaBi;
    bool find=false;
    int dia=1;
    int money=100;


public:

    Ilha() = delete;
    Ilha(const int l, const int c);


    string getZonaTipo(const int l, const int c){
        return ilhaBi[l-1][c-1]->getTipoZona();
    }

    void contWorker(const string t) { //Contrata Worker e envia-o para Pasto
        for(int i=0; i<ilhaBi.size(); i++) {
            for(int j=0; j<ilhaBi[i].size();j++) {
                if (ilhaBi[i][j]->getTipoZona() == "pas") {
                    find = true;
                    if(ilhaBi[i][j]->addTrabalhador(t,money,dia)) {
                        money = money - ilhaBi[i][j]->workerCost(t);
                    }
                }
                if(find){break;}
            }
            if(find){break;}
        }
        find=false;
    }

    void newDay(){
        dia++;
        for(int i=0; i<ilhaBi.size(); i++) {
            for(int j=0; j<ilhaBi[i].size();j++) {
                ilhaBi[i][j]->newDay();
            }
        }
    }

    void moveWorker(const int id,const int linha, const int coluna) {
        if(ilhaBi[linha-1][coluna-1]->iHaveThisId(id)){ //Se já estiver na Zona pretendida
            find=true;
            cout << "Trabalhador ja se encontra na Zona pretendida." << endl;
        }
        if(!find) { //Se não se encontrar na Zona pretendida
            for (int i = 0; i < ilhaBi.size(); i++) {
                for (int j = 0; j < ilhaBi[i].size(); j++) {
                    if (ilhaBi[i][j]->iHaveThisId(id)) {
                        find = true; //Foi encontrado
                        auto e = ilhaBi[i][j];
                        ilhaBi[linha - 1][coluna - 1]->moveToHere((*e).passWorkerRef(id));
                        (*e).removeWorker(id);
                    }
                }
            }
        }
        if(!find){//Se não existir
            cout << "Id inexistente..." << endl;
        }
        find = false;
    }

    void listZona(const int linha, const int coluna){
        cout << ilhaBi[linha-1][coluna-1]->getAsString();
    }

    void
    showIlha();

};


#endif //PRATICOTRABALHO_ILHA_H
