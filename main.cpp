#include <iostream>
#include <cstdlib>
#include "Ilha.h"


int main() {

   // cout << RED << "hello world" << RESET << endl;

    Ilha I(5,5);

    int linha;
    int coluna;
    int id;
    int option;
    string tipo;




    I.showIlha();



   while(1){
        cout << "1 - Contratar Worker. (oper/len/miner)" << endl;
        cout << "2 - Mover Worker." << endl;
        cout << "3 - Listar Zona." << endl;
        cout << "4 - Construir Edificio. (mnC/mnF/bat/fun)" << endl;
        cout << "5 - New Day." << endl;
        cout << "6 - Produzir." << endl;
        cout << ">>  ";
        scanf("%d",&option);

        switch (option) {


            case 1:
                cout << "Tipo: ";
                cin >> tipo;
                I.contWorker(tipo);
                I.showIlha();
                break;

            case 2:
                cout << "Linha: ";
                scanf("%d", &linha);
                cout << "Coluna: ";
                scanf("%d", &coluna);
                cout << "Id: ";
                scanf("%d", &id);
                I.moveWorker(id, linha, coluna);
                I.showIlha();
                break;

            case 3:
                cout << "Linha: ";
                scanf("%d", &linha);
                cout << "Coluna: ";
                scanf("%d", &coluna);
                I.listZona(linha, coluna);
                I.showIlha();
                break;

            case 4:
                cout << "Tipo: ";
                cin >> tipo;
                cout << "Linha: ";
                scanf("%d", &linha);
                cout << "Coluna: ";
                scanf("%d", &coluna);
                I.addEdi(tipo,linha,coluna);
                I.showIlha();
                break;

            case 5:
                I.newDay();
                I.showIlha();
                break;

            case 6:
                I.produzir();
                I.showIlha();
                break;

            case 0:
                exit(1);
        }
    }

}
