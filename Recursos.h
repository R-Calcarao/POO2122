
#ifndef PRATICOTRABALHO_RECURSOS_H
#define PRATICOTRABALHO_RECURSOS_H


class Recursos {

    int money=10000;
    float madeira=0;
    float ferro=5;
    int barraAco=0;
    float carvao=5;
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

    void withdrawFerro(const float cost) {
        ferro = ferro - cost;
    }

    void addFerro(const float add) {
        ferro = ferro + add;
    }

    int getBarraAco() const{
        return barraAco;
    }

    void addBarraAco(const int add) {
        barraAco = barraAco + add;
    }

    float getCarvao() const{
        return carvao;
    }

    void withdrawCarvao(const float cost){
        carvao = carvao - cost;
    }

    void addCarvao(const float add) {
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
