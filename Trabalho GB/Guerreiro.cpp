#include "Guerreiro.h"
#include "Defesa.h"
#include <iostream>

using namespace std;

Guerreiro::Guerreiro(const string& nome, int level)
    : Personagem(nome, level, 100 + level * 10), Forca(30 + level*5) {}

Guerreiro::~Guerreiro() {}

string Guerreiro::tipo() const {
    return "Guerreiro";
}

int Guerreiro::atacar(Personagem* target){
    if(!target) return 0;

    int dano = 10 + level * 2;

    if(Defesa* d = dynamic_cast<Defesa*>(target)){
        dano -= d->getArmadura() / 2;
        if (dano < 1) dano = 1;
    }

    target->setHP(target->getHP() - dano);
    cout << nome << " atacou " << target->getNome() << " causando " << dano << " de dano. \n";

    incTurno();
    return dano;
}

int Guerreiro::especial(Personagem* target){
    if(!target) return 0;

    if(turno >= 3){
        int dano = especialValue;

        if(Defesa* d = dynamic_cast<Defesa*>(target)){
            dano -= d->getArmadura();
            if (dano < 1) dano = 1;
        }

        target->setHP(target->getHP() - dano);
        cout << nome << " usou GOLPE ESPECIAL causando " << dano << " de dano em " << target->getNome() << "! \n";

        resetTurno();
        return dano;
    }

    cout << nome << " tentou usar especial, mas não está pronto ainda! \n";
    incTurno();
    return 0;
}

void Guerreiro::supporte(Personagem* ally){
    if(!ally) return;
    int cura = 5 + level * 4;
    ally->setHP(ally-> getHP() + cura);
    cout << nome << " curou " << ally->getNome() << " em " << cura << " HP. \n";
}