

#ifndef PRATICOTRABALHO_ILHA_H
#define PRATICOTRABALHO_ILHA_H

#include "Zona.h"
#include "Recursos.h"
#include <vector>

using namespace std;

class Ilha {
    //Deve existir pelo menos uma zona de cada tipo
    //Deve haver um equilibrio na distribuição do número de zonas na ilha
    const int linhas;
    const int colunas;
    vector<vector<Zona*>> ilhaBi;
    Recursos* recursos;
    bool find=false;
    int dia=1;


public:

    Ilha() = delete;
    Ilha(const int l, const int c);


    string getZonaTipo(const int l, const int c){
        return ilhaBi[l-1][c-1]->getTipoZona();
    }

    bool HaveflrAround(const int linha, const int coluna) const{
        if(coluna > 0 && coluna < this->colunas-1 && linha > 0 && linha < this->linhas-1){
            if(ilhaBi[linha][coluna-1]->getTipoZona() == "flr" // à esquerda e direita
               &&ilhaBi[linha][coluna-1]->HaveProduceThisDay()
               ||ilhaBi[linha][coluna+1]->getTipoZona() == "flr"
               &&ilhaBi[linha][coluna+1]->HaveProduceThisDay()
               ||ilhaBi[linha-1][coluna]->getTipoZona() == "flr"
               &&ilhaBi[linha-1][coluna]->HaveProduceThisDay()
               ||ilhaBi[linha+1][coluna]->getTipoZona() == "flr"
               &&ilhaBi[linha+1][coluna]->HaveProduceThisDay()) {
                return true;
            }
        } else if(linha == 0 && coluna > 0 && coluna < this->colunas-1) {
            if(ilhaBi[linha+1][coluna]->getTipoZona() == "flr"
               &&ilhaBi[linha+1][coluna]->HaveProduceThisDay()
               ||ilhaBi[linha][coluna-1]->getTipoZona() == "flr"
               &&ilhaBi[linha][coluna-1]->HaveProduceThisDay()
               ||ilhaBi[linha][coluna+1]->getTipoZona() == "flr"
               &&ilhaBi[linha][coluna+1]->HaveProduceThisDay()) {
                return true;
            }
        } else if(linha == 0 && coluna == 0) {
            if(ilhaBi[linha+1][coluna]->getTipoZona() == "flr"
               &&ilhaBi[linha+1][coluna]->HaveProduceThisDay()
               ||ilhaBi[linha][coluna+1]->getTipoZona() == "flr"
               &&ilhaBi[linha][coluna+1]->HaveProduceThisDay()) {
                return true;
            }
        } else if(coluna == 0 && linha > 0 && linha < this->linhas-1) {
            if(ilhaBi[linha][coluna+1]->getTipoZona() == "flr"
               &&ilhaBi[linha][coluna+1]->HaveProduceThisDay()
               ||ilhaBi[linha-1][coluna]->getTipoZona() == "flr"
               &&ilhaBi[linha-1][coluna]->HaveProduceThisDay()
               ||ilhaBi[linha+1][coluna]->getTipoZona() == "flr"
               &&ilhaBi[linha+1][coluna]->HaveProduceThisDay()) {
                return true;
            }
        } else if(coluna == 0 && linha == this->linhas-1) {
            if(ilhaBi[linha-1][coluna]->getTipoZona() == "flr"
               &&ilhaBi[linha-1][coluna]->HaveProduceThisDay()
               ||ilhaBi[linha][coluna+1]->getTipoZona() == "flr"
               &&ilhaBi[linha][coluna+1]->HaveProduceThisDay()) {
                return true;
            }
        } else if(linha == this->linhas-1 && coluna > 0 && coluna < this->colunas-1) {
            if(ilhaBi[linha][coluna-1]->getTipoZona() == "flr"
               &&ilhaBi[linha][coluna-1]->HaveProduceThisDay()
               ||ilhaBi[linha][coluna+1]->getTipoZona() == "flr"
               &&ilhaBi[linha][coluna+1]->HaveProduceThisDay()
               ||ilhaBi[linha-1][coluna]->getTipoZona() == "flr"
               &&ilhaBi[linha-1][coluna]->HaveProduceThisDay()){
                return true;
            }
        } else if(linha == 0 && coluna == this->colunas-1) {
            if(ilhaBi[linha+1][coluna]->getTipoZona() == "flr"
               &&ilhaBi[linha+1][coluna]->HaveProduceThisDay()
               ||ilhaBi[linha][coluna-1]->getTipoZona() == "flr"
               &&ilhaBi[linha][coluna-1]->HaveProduceThisDay()) {
                return true;
            }
        } else if(coluna == this->colunas-1 && linha > 0 && linha < this->linhas-1) {
            if(ilhaBi[linha][coluna-1]->getTipoZona() == "flr"
               &&ilhaBi[linha][coluna-1]->HaveProduceThisDay()
               ||ilhaBi[linha-1][coluna]->getTipoZona() == "flr"
               &&ilhaBi[linha-1][coluna]->HaveProduceThisDay()
               ||ilhaBi[linha+1][coluna]->getTipoZona() == "flr"
               &&ilhaBi[linha+1][coluna]->HaveProduceThisDay()) {
                return true;
            }
        } else if(linha == this->linhas-1 && coluna == this->colunas-1) {
            if(ilhaBi[linha-1][coluna]->getTipoZona() == "flr"
               &&ilhaBi[linha-1][coluna]->HaveProduceThisDay()
               ||ilhaBi[linha][coluna-1]->getTipoZona() == "flr"
               &&ilhaBi[linha][coluna-1]->HaveProduceThisDay()) {
                return true;
            }
        }
        return false;
    }

    bool HaveMnAround(const int linha, const int coluna) const{
        //if(coluna > 0 && coluna < this->colunas ){
        /*cout << "0" << endl;
            if(ilhaBi[linha][coluna-1]->getTipoEdificio() == "mnC"){
                cout << "1" << endl;
                if(ilhaBi[linha][coluna+1]->getTipoEdificio() == "mnF"){
                    cout << "2" << endl;
                    return true;
                }
            } else if(ilhaBi[linha][coluna-1]->getTipoEdificio() == "mnF"){
                cout << "3" << endl;
                if(ilhaBi[linha][coluna+1]->getTipoEdificio() == "mnC"){
                    cout << "4" << endl;
                    return true;
                }
            }*/
        //}

        /*if(ilhaBi[linha][coluna-1]->getTipoEdificio() == "elec" // procurar por centrais
        || ilhaBi[linha][coluna+1]->getTipoEdificio() == "elec"
        || ilhaBi[linha-1][coluna]->getTipoEdificio() == "elec"
        || ilhaBi[linha+1][coluna]->getTipoEdificio() == "elec") {
            return true;
        }
        else if(ilhaBi[linha][coluna-1]->getTipoEdificio() == "mnC" // à esquerda e direita
        && ilhaBi[linha][coluna+1]->getTipoEdificio() == "mnF"
        || ilhaBi[linha][coluna-1]->getTipoEdificio() == "mnF"
        && ilhaBi[linha][coluna+1]->getTipoEdificio() == "mnC") {
            return true;
        }
        else if(ilhaBi[linha+1][coluna]->getTipoEdificio() == "mnC" // em cima e em baixo
        && ilhaBi[linha-1][coluna]->getTipoEdificio() == "mnF"
        || ilhaBi[linha+1][coluna]->getTipoEdificio() == "mnF"
        && ilhaBi[linha-1][coluna]->getTipoEdificio() == "mnC") {
            return true;
        }*/
       /* else {
            return false;
        }
        return false;*/

        /*cout << "Zona que tem uma Fundicao: " << ilhaBi[linha][coluna]->getTipoZona() << endl;
        cout << "Seu edi -> " << ilhaBi[linha][coluna]->getTipoEdificio() << endl;
        cout << "Zona atras: " << ilhaBi[linha][coluna-1]->getTipoZona() << endl;
        cout << "Seu edi -> " << ilhaBi[linha][coluna-1]->getTipoEdificio() << endl;
        cout << "Zona a frente: " << ilhaBi[linha][coluna+1]->getTipoZona() << endl;
        cout << "Seu edi -> " << ilhaBi[linha][coluna+1]->getTipoEdificio() << endl;
        cout << "Zona acima: " << ilhaBi[linha-1][coluna]->getTipoZona() << endl;
        cout << "Seu edi -> " << ilhaBi[linha-1][coluna]->getTipoEdificio() << endl;
        cout << "Zona abaixo: " << ilhaBi[linha+1][coluna]->getTipoZona() << endl;
        cout << "Seu edi -> " << ilhaBi[linha+1][coluna]->getTipoEdificio() << endl;*/

        /*cout << "Numero de linhas da Ilha: " << linhas << endl;
        cout << "Numero de colunas da Ilha: " << colunas << endl;
        cout << "Posicao da Zona: " << linha << " , " << coluna << endl;*/


        if(coluna > 0 && coluna < this->colunas-1 && linha > 0 && linha < this->linhas-1){
            //cout << "1" << endl;
               if(ilhaBi[linha][coluna-1]->getTipoEdificio() == "mnC" // à esquerda e direita
               && ilhaBi[linha][coluna+1]->getTipoEdificio() == "mnF") {
                   return true;
               }
               else if(ilhaBi[linha][coluna-1]->getTipoEdificio() == "mnF"
               && ilhaBi[linha][coluna+1]->getTipoEdificio() == "mnC") {
                   return true;
               }
               else if(ilhaBi[linha-1][coluna]->getTipoEdificio() == "mnC"
               && ilhaBi[linha+1][coluna]->getTipoEdificio() == "mnF") {
                   return true;
               }
               else if(ilhaBi[linha-1][coluna]->getTipoEdificio() == "mnF"
               && ilhaBi[linha+1][coluna]->getTipoEdificio() == "mnC"){
                   return true;
               } else if(ilhaBi[linha][coluna-1]->getTipoEdificio() == "elec" // à esquerda e direita
                         ||ilhaBi[linha][coluna+1]->getTipoEdificio() == "elec"
                         ||ilhaBi[linha-1][coluna]->getTipoEdificio() == "elec"
                         ||ilhaBi[linha+1][coluna]->getTipoEdificio() == "elec") {
                   return true;
               }
        } else if(linha == 0 && coluna > 0 && coluna < this->colunas-1) {
            //cout << "2" << endl;
            if(ilhaBi[linha+1][coluna]->getTipoEdificio() == "mnC"
              &&ilhaBi[linha][coluna-1]->getTipoEdificio() == "mnF"
              ||ilhaBi[linha+1][coluna]->getTipoEdificio() == "mnF"
              &&ilhaBi[linha][coluna-1]->getTipoEdificio() == "mnC"
              ||ilhaBi[linha+1][coluna]->getTipoEdificio() == "mnC"
              &&ilhaBi[linha][coluna+1]->getTipoEdificio() == "mnF"
              ||ilhaBi[linha+1][coluna]->getTipoEdificio() == "mnF"
              &&ilhaBi[linha][coluna+1]->getTipoEdificio() == "mnC"
              ||ilhaBi[linha][coluna-1]->getTipoEdificio() == "mnC"
              &&ilhaBi[linha][coluna+1]->getTipoEdificio() == "mnF"
              ||ilhaBi[linha][coluna-1]->getTipoEdificio() == "mnF"
              &&ilhaBi[linha][coluna+1]->getTipoEdificio() == "mnC") {
                     return true;
            } else if(ilhaBi[linha+1][coluna]->getTipoEdificio() == "elec"
                     ||ilhaBi[linha][coluna-1]->getTipoEdificio() == "elec"
                     ||ilhaBi[linha][coluna+1]->getTipoEdificio() == "elec") {
                                return true;
                   }
        }  else if(linha == 0 && coluna == 0) {
            //cout << "3" << endl;
            if(ilhaBi[linha+1][coluna]->getTipoEdificio() == "mnC"
             &&ilhaBi[linha][coluna+1]->getTipoEdificio() == "mnF") {
                return true;
            } else if(ilhaBi[linha+1][coluna]->getTipoEdificio() == "mnF"
                      &&ilhaBi[linha][coluna+1]->getTipoEdificio() == "mnC") {
                return true;
            } else if(ilhaBi[linha+1][coluna]->getTipoEdificio() == "elec"
                      ||ilhaBi[linha][coluna+1]->getTipoEdificio() == "elec") {
                return true;
            }
        } else if(coluna == 0 && linha > 0 && linha < this->linhas-1) {
            //cout << "4" << endl;
            if(ilhaBi[linha-1][coluna]->getTipoEdificio() == "mnC"
             &&ilhaBi[linha+1][coluna]->getTipoEdificio() == "mnF"
             ||ilhaBi[linha-1][coluna]->getTipoEdificio() == "mnF"
             &&ilhaBi[linha+1][coluna]->getTipoEdificio() == "mnC"
             ||ilhaBi[linha][coluna+1]->getTipoEdificio() == "mnC"
             &&ilhaBi[linha-1][coluna]->getTipoEdificio() == "mnF"
             ||ilhaBi[linha][coluna+1]->getTipoEdificio() == "mnF"
             &&ilhaBi[linha-1][coluna]->getTipoEdificio() == "mnC"
             ||ilhaBi[linha][coluna+1]->getTipoEdificio() == "mnC"
             &&ilhaBi[linha+1][coluna]->getTipoEdificio() == "mnF"
             ||ilhaBi[linha][coluna+1]->getTipoEdificio() == "mnF"
             &&ilhaBi[linha+1][coluna]->getTipoEdificio() == "mnC") {
                return true;
            } else if(ilhaBi[linha][coluna+1]->getTipoEdificio() == "elec"
                    ||ilhaBi[linha-1][coluna]->getTipoEdificio() == "elec"
                    ||ilhaBi[linha+1][coluna]->getTipoEdificio() == "elec") {
                return true;
            }
        } else if(coluna == 0 && linha == this->linhas-1) {
            //cout << "5" << endl;
            if(ilhaBi[linha-1][coluna]->getTipoEdificio() == "mnC"
             &&ilhaBi[linha][coluna+1]->getTipoEdificio() == "mnF"
             ||ilhaBi[linha-1][coluna]->getTipoEdificio() == "mnF"
               &&ilhaBi[linha][coluna+1]->getTipoEdificio() == "mnC") {
                return true;
            } else if(ilhaBi[linha-1][coluna]->getTipoEdificio() == "elec"
                    ||ilhaBi[linha][coluna+1]->getTipoEdificio() == "elec") {
                return true;
            }
        } else if(linha == this->linhas-1 && coluna > 0 && coluna < this->colunas-1) {
            //cout << "6" << endl;
            if(ilhaBi[linha-1][coluna]->getTipoEdificio() == "mnC"
               &&ilhaBi[linha][coluna-1]->getTipoEdificio() == "mnF"
               ||ilhaBi[linha-1][coluna]->getTipoEdificio() == "mnF"
               &&ilhaBi[linha][coluna-1]->getTipoEdificio() == "mnC"
               ||ilhaBi[linha-1][coluna]->getTipoEdificio() == "mnC"
               &&ilhaBi[linha][coluna+1]->getTipoEdificio() == "mnF"
               ||ilhaBi[linha-1][coluna]->getTipoEdificio() == "mnF"
               &&ilhaBi[linha][coluna+1]->getTipoEdificio() == "mnC"
               ||ilhaBi[linha][coluna-1]->getTipoEdificio() == "mnC"
               &&ilhaBi[linha][coluna+1]->getTipoEdificio() == "mnF"
               ||ilhaBi[linha][coluna-1]->getTipoEdificio() == "mnF"
               &&ilhaBi[linha][coluna+1]->getTipoEdificio() == "mnC") {
                return true;
            } else if(ilhaBi[linha][coluna-1]->getTipoEdificio() == "elec"
                    ||ilhaBi[linha][coluna+1]->getTipoEdificio() == "elec"
                    ||ilhaBi[linha-1][coluna]->getTipoEdificio() == "elec"){
                return true;
            }
        } else if(linha == 0 && coluna == this->colunas-1) {
            //cout << "7" << endl;
            if(ilhaBi[linha+1][coluna]->getTipoEdificio() == "mnC"
               &&ilhaBi[linha][coluna-1]->getTipoEdificio() == "mnF") {
                return true;
            } else if(ilhaBi[linha+1][coluna]->getTipoEdificio() == "mnF"
                      &&ilhaBi[linha][coluna-1]->getTipoEdificio() == "mnC") {
                return true;
            } else if(ilhaBi[linha+1][coluna]->getTipoEdificio() == "elec"
                      ||ilhaBi[linha][coluna-1]->getTipoEdificio() == "elec") {
                return true;
            }
        } else if(coluna == this->colunas-1 && linha > 0 && linha < this->linhas-1) {
            //cout << "8" << endl;
            if(ilhaBi[linha-1][coluna]->getTipoEdificio() == "mnC"
               &&ilhaBi[linha+1][coluna]->getTipoEdificio() == "mnF"
               ||ilhaBi[linha-1][coluna]->getTipoEdificio() == "mnF"
               &&ilhaBi[linha+1][coluna]->getTipoEdificio() == "mnC"
               ||ilhaBi[linha][coluna-1]->getTipoEdificio() == "mnC"
               &&ilhaBi[linha-1][coluna]->getTipoEdificio() == "mnF"
               ||ilhaBi[linha][coluna-1]->getTipoEdificio() == "mnF"
               &&ilhaBi[linha-1][coluna]->getTipoEdificio() == "mnC"
               ||ilhaBi[linha][coluna-1]->getTipoEdificio() == "mnC"
               &&ilhaBi[linha+1][coluna]->getTipoEdificio() == "mnF"
               ||ilhaBi[linha][coluna-1]->getTipoEdificio() == "mnF"
               &&ilhaBi[linha+1][coluna]->getTipoEdificio() == "mnC") {
                return true;
            } else if(ilhaBi[linha][coluna-1]->getTipoEdificio() == "elec"
                      ||ilhaBi[linha-1][coluna]->getTipoEdificio() == "elec"
                      ||ilhaBi[linha+1][coluna]->getTipoEdificio() == "elec") {
                return true;
            }
        } else if(linha == this->linhas-1 && coluna == this->colunas-1) {
            //cout << "9" << endl;
            if(ilhaBi[linha-1][coluna]->getTipoEdificio() == "mnC"
               &&ilhaBi[linha][coluna-1]->getTipoEdificio() == "mnF") {
                return true;
            } else if(ilhaBi[linha-1][coluna]->getTipoEdificio() == "mnF"
                      &&ilhaBi[linha][coluna-1]->getTipoEdificio() == "mnC") {
                return true;
            } else if(ilhaBi[linha-1][coluna]->getTipoEdificio() == "elec"
                      ||ilhaBi[linha][coluna-1]->getTipoEdificio() == "elec") {
                return true;
            }
        }


        /*if(ilhaBi[linha-1][coluna]->getTipoEdificio() == "mnC"
          &&ilhaBi[linha+1][coluna]->getTipoEdificio() == "mnF"
          ||ilhaBi[linha-1][coluna]->getTipoEdificio() == "mnF"
          &&ilhaBi[linha+1][coluna]->getTipoEdificio() == "mnC"
          ||ilhaBi[linha][coluna-1]->getTipoEdificio() == "mnC"
          &&ilhaBi[linha][coluna+1]->getTipoEdificio() == "mnF"
          ||ilhaBi[linha][coluna-1]->getTipoEdificio() == "mnF"
          &&ilhaBi[linha][coluna+1]->getTipoEdificio() == "mnC"
          ||ilhaBi[linha-1][coluna]->getTipoEdificio() == "mnC"
          &&ilhaBi[linha][coluna+1]->getTipoEdificio() == "mnF"
          ||ilhaBi[linha-1][coluna]->getTipoEdificio() == "mnF"
          &&ilhaBi[linha][coluna+1]->getTipoEdificio() == "mnC"
          ||ilhaBi[linha-1][coluna]->getTipoEdificio() == "mnC"
          &&ilhaBi[linha][coluna-1]->getTipoEdificio() == "mnF"
          ||ilhaBi[linha-1][coluna]->getTipoEdificio() == "mnF"
          &&ilhaBi[linha][coluna-1]->getTipoEdificio() == "mnC"
          ||ilhaBi[linha+1][coluna]->getTipoEdificio() == "mnC"
          &&ilhaBi[linha][coluna-1]->getTipoEdificio() == "mnF"
          ||ilhaBi[linha+1][coluna]->getTipoEdificio() == "mnF"
          &&ilhaBi[linha][coluna-1]->getTipoEdificio() == "mnC"
          ||ilhaBi[linha+1][coluna]->getTipoEdificio() == "mnC"
          &&ilhaBi[linha][coluna+1]->getTipoEdificio() == "mnF"
          ||ilhaBi[linha+1][coluna]->getTipoEdificio() == "mnF"
          &&ilhaBi[linha][coluna+1]->getTipoEdificio() == "mnC"){
            return true;
        } else if(ilhaBi[linha-1][coluna]->getTipoEdificio() == "elec"
                ||ilhaBi[linha+1][coluna]->getTipoEdificio() == "elec"
                ||ilhaBi[linha][coluna+1]->getTipoEdificio() == "elec"
                ||ilhaBi[linha][coluna-1]->getTipoEdificio() == "elec") {
            return true;
        }*/
        return false;
    }

    void contWorker(const string t) { //Contrata Worker e envia-o para Pasto
        for(int i=0; i<ilhaBi.size(); i++) {
            for(int j=0; j<ilhaBi[i].size();j++) {
                if (ilhaBi[i][j]->getTipoZona() == "pas") {
                    ilhaBi[i][j]->addTrabalhador(t,getDay());
                    find = true;
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

    void produzir() {
        for(int i=0; i<ilhaBi.size(); i++) {
            for(int j=0; j<ilhaBi[i].size();j++) {
                ilhaBi[i][j]->produzir();
            }
        }
    }

    int getDay() const{
        return dia;
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

    void addEdi(const string tipo,const int linha, const int coluna) {
        ilhaBi[linha-1][coluna-1]->addEdificio(tipo);
    }

    void showIlha();

};


#endif //PRATICOTRABALHO_ILHA_H
