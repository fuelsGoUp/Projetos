#include "Mago.h"
#include <iostream>

using namespace std;

Mago::Mago(const string& nome, int level)
    : Personagem(nome, level, 70 + level*6),
      Forca(40 + level*4),
      Defesa(5 + level*2) {}

Mago::~Mago() {}

int Mago::atacar(Personagem* target){
    if(!target) return 0;

    int dano = 0 + level * 3;
    if(Defesa* d = dynamic_cast<Defesa*>(target)){
        dano -= d->getArmadura() / 2;
        if(dano < 1) dano = 1;
    }

    target->setHP(target->getHP() - dano);
    cout << nome << " lançou magia em " << target->getNome() << " causando " << dano <<
     " de dano! " << endl;
    incTurno();
    return dano;
}

int Mago::especial(Personagem* target){
    if (!target) return 0;

    if (turno >= 3){
        int dano = especialValue;

        if(Defesa* d = dynamic_cast<Defesa*>(target)){
            dano -= d->getArmadura();
            if(dano < 1) dano = 1;
        }

        target->setHP(target->getHP() - dano);
        cout << nome << " usou EXPLOSÂO DE ENERGIA causando " << dano << "! \n";
        resetTurno();
        return dano; 
    }
    cout << nome << " ainda não tem o espcial! " << endl;
    incTurno();
    return 0;
}

void Mago::supporte(Personagem* ally){
    if(!ally) return;
    int cura = 10 + level;
    ally->setHP(ally->getHP() + cura);
    cout << nome << " curou " << ally->getNome() << " em " << cura << " HP." << endl;
}

