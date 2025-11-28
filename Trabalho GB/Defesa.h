#ifndef DEFESA_H
#define DEFESA_H

#include "Personagem.h"

class Defesa : virtual public Personagem {
    public:
        Defesa(int armadura = 0);
        virtual ~Defesa();

        int getArmadura() const;
        void setArmadura(int armadura);
    protected:
        int armadura;
};

#endif