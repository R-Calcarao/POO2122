

#include "Ilha.h"
#include "Deserto.h"
#include "Floresta.h"
#include "Pastagem.h"
#include "Montanha.h"
#include "Pantano.h"
#include "ZonaX.h"
#include <cstdlib>
#include <iostream>

using namespace std;



Ilha::Ilha(const int l, const int c) : linhas(l), colunas(c) {
    recursos = new Recursos();

    srand(time(0));

    for(int i=0; i<linhas; i++) {
        vector<Zona* > v1;
        for(int j=0; j<colunas; j++) {
            int f = (rand() % 6) + 1;
            switch (f) {
                case 1:
                    v1.push_back(new Deserto(i,j));
                    break;

                case 2:
                    v1.push_back(new Floresta(i,j));
                    break;

                case 3:
                    v1.push_back(new Pastagem(i,j));
                    break;

                case 4:
                    v1.push_back(new Montanha(i,j));
                    break;

                case 5:
                    v1.push_back(new Pantano(i,j));
                    break;

                case 6:
                    v1.push_back(new ZonaX(i,j));//Composição -> Zonas fazem parte da ilha
                    break;
            }
        }
        ilhaBi.push_back(v1);
    }

    for(int i=0; i<ilhaBi.size(); i++) {
        for(int j=0; j<ilhaBi[i].size();j++) {
            ilhaBi[i][j]->pointToRecursos(recursos);
            ilhaBi[i][j]->pointToIlha(this);
        }
    }
}

void Ilha::showIlha() { //Corre a ilha
cout << endl;
cout << "Dia: " << getDay() << endl;
cout << "Dinheiro: " << recursos->getMoney() << " euros" << endl;
cout << "Madeira: " << recursos->getMadeira() << " kg" << endl;
cout << "Ferro: " << recursos->getFerro() << " kg" << endl;
cout << "Carvao: " << recursos->getCarvao() << " kg" << endl;
cout << "Barras de Aco: " << recursos->getBarraAco() << endl;
cout << "Vigas de Madeira: " << recursos->getVigaMadeira() << endl;
cout << "Eletricidade: " << recursos->getEletricidade() << endl;
cout << endl;

    for(int i=0; i<ilhaBi.size(); i++) {
        for(int j=0; j<ilhaBi[i].size();j++) {
            cout << ilhaBi[i][j]->getTipoZona() << " - " << ilhaBi[i][j]->NumbWorkers()<< " / "
            << ilhaBi[i][j]->getNumEdificios() <<"     ";
        }
        cout << endl;
        cout << endl;
    }
    cout <<endl;
}
