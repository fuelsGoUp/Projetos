#ifndef FORCA_H
#define FORCA_H

#include "Personagem.h"

class Forca : virtual public Personagem {
    public:
        Forca(int especialValue = 10);
        virtual ~Forca();

        int getEspecialValue() const;
    protected:
        int especialValue;
        int turno;
        void incTurno();
        void resetTurno();
};

#endif