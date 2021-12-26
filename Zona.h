//
// Created by ACER on 23/12/2021.
//

#ifndef PRATICOTRABALHO_ZONA_H
#define PRATICOTRABALHO_ZONA_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstring>
#include "Trabalhadores.h"
#include "Edificio.h"
#include "MinaCarvao.h"
#include "MinaFerro.h"
#include "Bateria.h"
#include "Fundicao.h"
#include "Mineiro.h"
#include "Lenhador.h"
#include "Operario.h"

using namespace std;


class Zona {

    vector<Trabalhadores* > TrabalhadoresDaZona;
    vector<Edificio* > EdificioDaZona;
    int N_edificios;
    const string tipo;
    int Ferro;
    int BarraAco;
    int Carvao;
    int Madeira;
    int VigasMadeira;
    int Eletricidade;
    int day=1;

public:

    Zona(const string t) : tipo(t){
        N_edificios=0;
        Ferro=0;
        BarraAco=0;
        Carvao=0;
        Madeira=0;
        VigasMadeira=0;
        Eletricidade=0;
    };

    bool addTrabalhador(const string &t, const int money, const int dia) { //Recebe tipo e quantidade de dinheiro do Player

        if(t=="miner" && money >= 10){
            TrabalhadoresDaZona.push_back(new Mineiro(dia));//Push_back no vetor Trabalhadores da Zona(Pasto)
            auto e = (TrabalhadoresDaZona.end()-1);
            cout << (*e)->getTipo() <<" contratado" << " por " << (*e)->getPrice() <<"\n" <<endl;
            (*e)->entrarNaZona(this);//Trabalhador vai passar a apontar para a Zona em que se encontra
            return true;//Para que seja retirado dinheiro ao Player

        } else if(t=="len" && money >= 20){
            TrabalhadoresDaZona.push_back(new Lenhador(dia));
            auto e = (TrabalhadoresDaZona.end()-1);
            cout << (*e)->getTipo() <<" contratado" << " por " << (*e)->getPrice() <<"\n" <<endl;
            (*e)->entrarNaZona(this);
            return true;


        } else if(t=="oper" && money >= 15){
            TrabalhadoresDaZona.push_back(new Operario(dia));
            auto e = (TrabalhadoresDaZona.end()-1);
            cout << (*e)->getTipo() <<" contratado" << " por " << (*e)->getPrice() <<"\n" <<endl;
            (*e)->entrarNaZona(this);
            return true;

        } else {
            cout << "Tipo de trabalhador indisponivel(oper/miner/len), ou dinheiro insuficiente." << endl;
            return false;//Não é retirado dinheiro
        }

    }

    int workerCost(const string t){ //Recebe o tipo de Trabalhador contratado e dá return do preço do mesmo
                                    //que será descontado no dinheiro do Player
        if(t=="miner"){
            return 10;
        } else if(t=="oper"){
            return 15;
        } else if(t=="len"){
            return 20;
        }
        return 0;
    }

    void addEdificio(const string &t) {

        if(N_edificios==0) {
            if (t == "mnC") {
                EdificioDaZona.push_back(new MinaCarvao());
            } else if (t == "mnF") {
                EdificioDaZona.push_back(new MinaFerro());
            } else if (t == "bat") {
                EdificioDaZona.push_back(new Bateria());
            } else if (t == "fun") {
                EdificioDaZona.push_back(new Fundicao());
            } else {
                cout << "Tipo de Edificio nao existente." << endl;
            }
        } else {
            cout << "Esta Zona ja contem um Edificio." << endl;
        }
    }

    void moveToHere(Trabalhadores* abc){//Pega num determinado Worker do pasto e mete-o nesta zona
                                        //recebemo-lo em ponteiro e fazemos push_back e ele passa a apontar
                                        //para esta zona, na Ilha faz-se o erase no vector onde o Trabalhador estava antes
        TrabalhadoresDaZona.push_back(abc);
        auto e = (TrabalhadoresDaZona.end()-1);
        cout << (*e)->getTipo() << " movido para " << getTipoZona() << "\n" << endl;
        (*e)->entrarNaZona(this);//Passa a apontar para esta zona agora
    }

    void showWorkers() const {//Corre o Vetor dos Trabalhadores de Zona
        for(auto e = TrabalhadoresDaZona.begin(); e<TrabalhadoresDaZona.end(); e++) {
            cout << "Trabalhadores n@ " << getTipoZona() << " : " << (*e)->getTipo() << "." << (*e)->getContractDay() << endl;
        }
    }

    int NumbWorkers() const {//Conta o numero de trabalhadores da zona
        int count=0;
        for(auto e = TrabalhadoresDaZona.begin(); e<TrabalhadoresDaZona.end(); e++) {
            count++;
        }
        return count;
    }

    int getNumEdificios() const{
        return N_edificios;
    }

    bool iHaveThisId(const int i){//Recebe um id por argumento e corre o vetor de Trabalhadores para ver se tem
                                 // se tiver dá return de true.
        for(auto e = TrabalhadoresDaZona.begin(); e<TrabalhadoresDaZona.end(); e++) {
            if((*e)->getId()==i){
                return true;
            }
        }
        return false;
    }

    Trabalhadores* passWorkerRef(const int i){//Auxiliar no processo de movimentar o Trabalhador para outra zona
        for(auto e = TrabalhadoresDaZona.begin(); e<TrabalhadoresDaZona.end(); e++) {
            if((*e)->getId()==i){
                return *e;
            }
        }
        return nullptr;
    }

    void removeWorker(const int i){//Auxiliar no processo de mover Trabalhador de Zona
        for(auto e = TrabalhadoresDaZona.begin(); e<TrabalhadoresDaZona.end(); e++){
            if((*e)->getId()==i){
                TrabalhadoresDaZona.erase(e);
            }
        }
    }

    void newDay(){//Dar inicio ao Trabalhado dos Trabalhadores da Zona, é chamada uma função Virtual..
        day++;
        for(auto e = TrabalhadoresDaZona.begin(); e<TrabalhadoresDaZona.end(); e++){
            (*e)->newWorkDay();
        }
    }

    void fireWorker(const int i){//Caso um Trabalhador de demita num dia de Trabalho
        for(auto e = TrabalhadoresDaZona.begin(); e<TrabalhadoresDaZona.end(); e++){
            if((*e)->getId()==i){
                delete *e;
                TrabalhadoresDaZona.erase(e);
            }
        }
    }

    string getWorkerId() {
        ostringstream oss;
        for(auto e = TrabalhadoresDaZona.begin(); e<TrabalhadoresDaZona.end(); e++) {
            oss << (*e)->getId() << " ";
        }
        return oss.str();
    }

    string getTipoZona() const{
        return tipo;
    }

    string getAsString() {
        ostringstream oss;
        oss << endl;
        oss << "Tipo de Zona: " << getTipoZona() << endl;
        oss << "Trabalhadores da Zona:" << endl;
        for(auto e = TrabalhadoresDaZona.begin(); e<TrabalhadoresDaZona.end(); e++) {
            oss <<  "   Id: " << (*e)->getId() << "." << (*e)->getContractDay() << " - " << (*e)->getTipo() << endl;
        }
        oss << "Numero de edificios: " << getNumEdificios() << endl;
        oss << endl;
        return oss.str();
    }

    int getDay() const{
        return day;
    }



};


#endif //PRATICOTRABALHO_ZONA_H
