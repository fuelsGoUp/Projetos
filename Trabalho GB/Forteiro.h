#ifndef FORTEIRO_H
#define FORTEIRO_H

#include "Defesa.h"

using namespace std;

class Forteiro : public Defesa {
    public:
        Forteiro(const string& nome, int level);
        virtual ~Forteiro();

        string tipo() const override { return "Forteiro";}

        int atacar(Personagem* target) override;
        int especial(Personagem* target) override;
        void supporte(Personagem* ally) override;
};

#endif