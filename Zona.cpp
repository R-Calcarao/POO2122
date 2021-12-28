#include "Zona.h"
#include "Recursos.h"

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

void Zona::addMadeira(const int add) {
    recursos->addMadeira(add);
}

void Zona::addFerro(const float add) {
    recursos->addFerro(add);
}

void Zona::addEdificio(const string &t) {

    if(N_edificios==0) { //Se a zona n tiver edificios

        if (t == "mnC") {
            if(recursos->getVigaMadeira() >= 10) {
                recursos->withdrawVigas(10);
                EdificioDaZona.push_back(new MinaCarvao());
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
                        EdificioDaZona.push_back(new MinaCarvao());
                        cout << "Mina de Carvao construida em " << getTipoZona() << endl;
                        N_edificios++;
                    } else {
                        cout << "Nao tem dinheiro suficiente..." << endl;
                    }
                }
            }
        } else if (t == "mnF") {
            if(recursos->getVigaMadeira() >= 10) {
                recursos->withdrawVigas(10);
                EdificioDaZona.push_back(new MinaFerro());
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
                        EdificioDaZona.push_back(new MinaFerro());
                        cout << "Mina de Ferro construida em " << getTipoZona() << endl;
                        N_edificios++;
                    } else {
                        cout << "Nao tem dinheiro suficiente..." << endl;
                    }
                }
            }
        } else if (t == "bat") {
            EdificioDaZona.push_back(new Bateria());
            cout << "Bateria construida em " << getTipoZona() << endl;
            N_edificios++;
        } else if (t == "fun") {
            cout << "Fundicao construida em " << getTipoZona() << endl;
            EdificioDaZona.push_back(new Fundicao());
            N_edificios++;
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
