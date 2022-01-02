
#include "Lenhador.h"
#include "Zona.h"

void Lenhador::newWorkDay() {
    Trabalhadores::newWorkDay();
    dayCount++;
    if(giveZonaRef()->getTipoZona() != "mnt") { //Se nao estiver na montanha
        if(aux){
            rest = false; // Pronto para trabalhar +4 dias
            dayCount = 0; // counter é resetado
            aux = false;
        } else if(dayCount > 4) {
            rest = true; // Nao esta disponivel para trabalhar hoje
            aux = true; // flag ativada
        }
    } else { //Se tiver numa Montanha
        bool TrueFalse = (rand() % 100) < 5;
        if(TrueFalse){
            cout << "Vou me embora da zona: " << giveZonaRef()->getTipoZona() << ", sou o " << getTipo() << " de id: " <<
                 getId() << " . Adeus!!" << endl;
            giveZonaRef()->fireWorker(getId());
        }
    }
}
