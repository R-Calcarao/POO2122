//
// Created by ACER on 23/12/2021.
//

#include "Ilha.h"
#include "Zona.h"
#include "Recursos.h"
#include "CentralEletrica.h"

void Zona::addTrabalhador(const string &t,const int dia) { //Recebe tipo e quantidade de dinheiro do Player

    if(t=="miner" && recursos->getMoney() >= 10){

        recursos->withdrawMoney(10);
        TrabalhadoresDaZona.push_back(new Mineiro(dia));//Push_back no vetor Trabalhadores da Zona(Pasto)
        auto e = (TrabalhadoresDaZona.end()-1);
        cout << (*e)->getTipo() <<" contratado" << " por " << (*e)->getPrice() << " euros" <<"\n" <<endl;
        (*e)->entrarNaZona(this);//Trabalhador vai passar a apontar para a Zona em que se encontra

    } else if(t=="len" && recursos->getMoney() >= 20){

        recursos->withdrawMoney(20);
        TrabalhadoresDaZona.push_back(new Lenhador(dia));
        auto e = (TrabalhadoresDaZona.end()-1);
        cout << (*e)->getTipo() <<" contratado" << " por " << (*e)->getPrice() << " euros" <<"\n" <<endl;
        (*e)->entrarNaZona(this);


    } else if(t=="oper" && recursos->getMoney() >= 15){

        recursos->withdrawMoney(15);
        TrabalhadoresDaZona.push_back(new Operario(dia));
        auto e = (TrabalhadoresDaZona.end()-1);
        cout << (*e)->getTipo() <<" contratado" << " por " << (*e)->getPrice() << " euros" <<"\n" <<endl;
        (*e)->entrarNaZona(this);

    } else {
        cout << "Tipo de trabalhador indisponivel(oper/miner/len), ou dinheiro insuficiente." << endl;
    }
}

int Zona::getMadeira() const{
    return recursos->getMadeira();
}

void Zona::addMadeira(const int add) {
    recursos->addMadeira(add);
}

void Zona::withdrawMadeira(const int cost) {
    recursos->withdrawMadeira(cost);
}

void Zona::addBarraAco(const int add) {
    recursos->addBarraAco(add);
}

int Zona::getFerro() const{
    return recursos->getFerro();
}

int Zona::getCarvao() const {
    return recursos->getCarvao();
}

void Zona::addFerro(const float add) {
    recursos->addFerro(add);
}

void Zona::addCarvao(const int add) {
    recursos->addCarvao(add);
}

void Zona::withdrawCarvao(const float cost) {
    recursos->withdrawCarvao(cost);
}

void Zona::withdrawFerro(const float cost) {
    recursos->withdrawFerro(cost);
}

bool Zona::HavemnAround() {
    if(ilha->HaveMnAround(linha,coluna)){
        return true;
    } else {
        return false;
    }
}

bool Zona::HaveflrAround() {
    if(ilha->HaveflrAround(linha,coluna)){
        return true;
    } else {
        return false;
    }
}

void Zona::addEdificio(const string &t) {

    if(N_edificios==0) { //Se a zona n tiver edificios

        if (t == "mnC" && getTipoZona()=="mnt") {
            if(recursos->getVigaMadeira() >= 20) {
                recursos->withdrawVigas(20);
                EdificioDaZona.push_back(new MinaCarvao(getDay()));
                cout << "Mina de Carvao construida em " << getTipoZona() << endl;
            } else { //Se n houver vigas suficientes
                int rest = 20 - recursos->getVigaMadeira();
                cout << "Nao tem vigas de madeira suficientes, faltam-lhe " << rest << " vigas." << endl;
                rest = rest*20;
                cout << "O restante custa: " << rest << " euros" << endl;
                cout << "Pretende pagar as vigas restantes com dinheiro?(S/N): ";
                char resp;
                cin >> resp;
                if(resp == 'S'){
                    if(recursos->getMoney() >= rest){
                        recursos->withdrawVigas(recursos->getVigaMadeira()); //Zerar as vigas umas vez que n há suf...
                        recursos->withdrawMoney(rest);
                        EdificioDaZona.push_back(new MinaCarvao(getDay()));
                        cout << "Mina de Carvao construida em " << getTipoZona() << endl;
                        N_edificios++;
                    } else {
                        cout << "Nao tem dinheiro suficiente..." << endl;
                    }
                }
            }
        } else if (t == "mnC") {
            if(recursos->getVigaMadeira() >= 10) {
                recursos->withdrawVigas(10);
                EdificioDaZona.push_back(new MinaCarvao(getDay()));
                cout << "Mina de Carvao construida em " << getTipoZona() << endl;
            } else { //Se n houver vigas suficientes
                int rest = 10 - recursos->getVigaMadeira();
                cout << "Nao tem vigas de madeira suficientes, faltam-lhe " << rest << " vigas." << endl;
                rest = rest*10;
                cout << "O restante custa: " << rest << " euros" << endl;
                cout << "Pretende pagar as vigas restantes com dinheiro?(S/N): ";
                char resp;
                cin >> resp;
                if(resp == 'S'){
                    if(recursos->getMoney() >= rest){
                        recursos->withdrawVigas(recursos->getVigaMadeira()); //Zerar as vigas umas vez que n há suf...
                        recursos->withdrawMoney(rest);
                        EdificioDaZona.push_back(new MinaCarvao(getDay()));
                        cout << "Mina de Carvao construida em " << getTipoZona() << endl;
                        N_edificios++;
                    } else {
                        cout << "Nao tem dinheiro suficiente..." << endl;
                    }
                }
            }
        } else if (t == "mnF" && getTipoZona()=="mnt") {
            if(recursos->getVigaMadeira() >= 20) {
                recursos->withdrawVigas(20);
                EdificioDaZona.push_back(new MinaFerro(getDay()));
                cout << "Mina de Ferro construida em " << getTipoZona() << endl;
            } else {// Se n houver vigas sufientes
                int rest = 20 - recursos->getVigaMadeira();
                cout << "Nao tem vigas de madeira suficientes, faltam-lhe " << rest << " vigas." << endl;
                rest = rest*20;
                cout << "O restante custa: " << rest << " euros" << endl;
                cout << "Pretende pagar as vigas restantes com dinheiro?(S/N): ";
                char resp;
                cin >> resp;
                if(resp == 'S'){
                    if(recursos->getMoney() >= rest){
                        recursos->withdrawVigas(recursos->getVigaMadeira()); //Zerar as vigas umas vez que n há suf...
                        recursos->withdrawMoney(rest);
                        EdificioDaZona.push_back(new MinaFerro(getDay()));
                        cout << "Mina de Ferro construida em " << getTipoZona() << endl;
                        N_edificios++;
                    } else {
                        cout << "Nao tem dinheiro suficiente..." << endl;
                    }
                }
            }
        } else if (t == "mnF") {
            if(recursos->getVigaMadeira() >= 10) {
                recursos->withdrawVigas(10);
                EdificioDaZona.push_back(new MinaFerro(getDay()));
                cout << "Mina de Ferro construida em " << getTipoZona() << endl;
            } else {// Se n houver vigas sufientes
                int rest = 10 - recursos->getVigaMadeira();
                cout << "Nao tem vigas de madeira suficientes, faltam-lhe " << rest << " vigas." << endl;
                rest = rest*10;
                cout << "O restante custa: " << rest << " euros" << endl;
                cout << "Pretende pagar as vigas restantes com dinheiro?(S/N): ";
                char resp;
                cin >> resp;
                if(resp == 'S'){
                    if(recursos->getMoney() >= rest){
                        recursos->withdrawVigas(recursos->getVigaMadeira()); //Zerar as vigas umas vez que n há suf...
                        recursos->withdrawMoney(rest);
                        EdificioDaZona.push_back(new MinaFerro(getDay()));
                        cout << "Mina de Ferro construida em " << getTipoZona() << endl;
                        N_edificios++;
                    } else {
                        cout << "Nao tem dinheiro suficiente..." << endl;
                    }
                }
            }
        } else if (t == "bat") {
            EdificioDaZona.push_back(new Bateria(getDay()));
            cout << "Bateria construida em " << getTipoZona() << endl;
            N_edificios++;
        } else if (t == "fun" && getTipoZona()=="mnt") {
            if(recursos->getMoney() >= 20) {
                recursos->withdrawMoney(20);
                cout << "Fundicao construida em " << getTipoZona() << endl;
                EdificioDaZona.push_back(new Fundicao(getDay()));
                N_edificios++;
            } else {
                cout << "Dinheiro insuficiente..." << endl;
            }
        } else if(t == "fun"){
            if(recursos->getMoney() >= 10){
                recursos->withdrawMoney(10);
                EdificioDaZona.push_back(new Fundicao(getDay()));
                N_edificios++;
            } else {
                cout << "Dinheiro insuficiente..." << endl;
            }
        } else if (t == "elec") {
            if(recursos->getMoney()>=15){
                cout << "Central Eletrica construida em " << getTipoZona() << endl;
                EdificioDaZona.push_back(new CentralEletrica(getDay()));
                N_edificios++;
            }
        } else {
            cout << "Tipo de Edificio nao existente." << endl;
        }
    } else {
        cout << "Esta Zona ja contem um Edificio." << endl;
    }
    if(N_edificios==1) {
        for (auto e = EdificioDaZona.begin(); e < EdificioDaZona.end(); e++) {
            (*e)->pointToRecursos(recursos);
            (*e)->pointToZona(this);
        }
    }
}
