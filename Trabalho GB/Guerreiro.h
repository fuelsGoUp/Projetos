#ifndef GUERREIRO_H
#define GUERREIRO_H

#include "Forca.h"

using namespace std;

class Guerreiro : public Forca {
    public:
        Guerreiro(const string& nome, int level);
        virtual ~Guerreiro();

        string tipo() const override;

        int atacar(Personagem* target) override;
        int especial(Personagem* target) override;
        void supporte(Personagem* ally) override;
};

#endif