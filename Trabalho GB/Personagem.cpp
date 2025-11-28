#include "Personagem.h"

using namespace std;

Personagem::Personagem(const string& nome, int level, int hp)
    : nome(nome), level(level), hp(hp) {}

Personagem::~Personagem() {}

const string& Personagem::getNome() const {
    return nome;
}
int Personagem::getLevel() const {
    return level;
}
int Personagem::getHP() const {
    return hp;
}
void Personagem::setHP(int hp) {
    this->hp = hp;
}