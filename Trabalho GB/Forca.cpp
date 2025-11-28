#include "Forca.h"

Forca::Forca(int especialValue)
    : Personagem(), especialValue(especialValue), turno(0) {}

Forca::~Forca() {}

int Forca::getEspecialValue() const { return especialValue; }

void Forca::incTurno() { turno++; }
void Forca::resetTurno() { turno = 0; }