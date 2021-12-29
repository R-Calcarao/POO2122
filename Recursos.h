//
// Created by ACER on 26/12/2021.
//

#ifndef PRATICOTRABALHO_RECURSOS_H
#define PRATICOTRABALHO_RECURSOS_H


class Recursos {

    int money=10000;
    float madeira=0;
    float ferro=0;
    int barraAco=0;
    float carvao=0;
    int vigaMadeira=5;
    int eletricidade=0;

public:

    void teste();

    int getMoney() const{
        return money;
    }

    void withdrawMoney(const int cost) {
        money = money - cost;
    }

    void addMoney(const int add) {
        money = money + add;
    }

    float getMadeira() const{
        return madeira;
    }

    void withdrawMadeira(const int cost) {
        madeira = madeira - cost;
    }

    void addMadeira(const int add) {
        madeira=madeira+add;
    }

    float getFerro() const{
        return ferro;
    }

    void withdrawFerro(const int cost) {
        ferro = ferro - cost;
    }

    void addFerro(const float add) {
        ferro=ferro+add;
    }

    int getBarraAco() const{
        return barraAco;
    }

    float getCarvao() const{
        return carvao;
    }

    void addCarvao(const int add) {
        carvao = carvao + add;
    }

    int getVigaMadeira() const{
        return vigaMadeira;
    }

    void withdrawVigas(const int cost) {
        vigaMadeira = vigaMadeira - cost;
    }

    int getEletricidade() const{
        return eletricidade;
    }

};


#endif //PRATICOTRABALHO_RECURSOS_H
