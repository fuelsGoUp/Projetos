#ifndef MAGO_H
#define MAGO_H

#include "Forca.h"
#include "Defesa.h"

using namespace std;

class Mago : public Forca, public Defesa {
    public:
        Mago(const string& nome, int level);
        virtual ~Mago();

        string tipo() const override { return "Mago";}

        int atacar(Personagem* target) override;
        int especial(Personagem* target) override;
        void supporte(Personagem* ally) override;
};

#endif