//
// Created by ACER on 23/12/2021.
//

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
    srand(time(0));

    for(int i=0; i<linhas; i++) {
        vector<Zona* > v1;
        for(int j=0; j<colunas; j++) {
            int f = (rand() % 6) + 1;
            switch (f) {
                case 1:
                    v1.push_back(new Deserto());
                    break;

                case 2:
                    v1.push_back(new Floresta());
                    break;

                case 3:
                    v1.push_back(new Pastagem());
                    break;

                case 4:
                    v1.push_back(new Montanha());
                    break;

                case 5:
                    v1.push_back(new Pantano());
                    break;

                case 6:
                    v1.push_back(new ZonaX());//Composição -> Zonas fazem parte da ilha
                    break;
            }
        }
        ilhaBi.push_back(v1);
    }
}

void Ilha::showIlha() { //Corre a ilha
cout << "Dinheiro: " << money << endl;
    for(int i=0; i<ilhaBi.size(); i++) {
        for(int j=0; j<ilhaBi[i].size();j++) {
            cout << ilhaBi[i][j]->getTipoZona() << " - " << ilhaBi[i][j]->NumbWorkers()<< " ";
        }
        cout << endl;
    }
    cout <<endl;
}
