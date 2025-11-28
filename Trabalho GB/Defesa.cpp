#include "Defesa.h"

Defesa::Defesa(int armadura)
    : Personagem(), armadura(armadura) {}

Defesa::~Defesa() {}

int Defesa::getArmadura() const { return armadura; }
void Defesa::setArmadura(int a) { armadura = a; }