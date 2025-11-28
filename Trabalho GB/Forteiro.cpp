#include "Forteiro.h"
#include <iostream>

using namespace std;

Forteiro::Forteiro(const string& nome, int level)
    : Personagem(nome, level, 150 + level * 12), Defesa(15 + level * 3) {}

Forteiro::~Forteiro() {}

int Forteiro::atacar(Personagem* target){
    if(!target) return 0;
    int dano = 5 + level;
    target->setHP(target->getHP() - dano);
    cout << nome << " esmagou " << target->getNome() << " causando " << dano << " de dano." << endl;
    return dano;
}

int Forteiro::especial(Personagem* target){
    cout << nome << " reduziu o dano do oponente! " << endl;
    return 0;
}

void Forteiro::supporte(Personagem* ally){
    if(!ally) return;
    int cura = 10 + level * 5;
    ally->setHP(ally-> getHP() + cura);
    cout << nome << " fortaleceu " << ally->getNome() << " em " << cura << " HP. " << endl;
}