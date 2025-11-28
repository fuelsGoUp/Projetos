#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <string>

using namespace std;

class Personagem {
public:
    Personagem(const string& nome = "Personagem não nomeado", int level = 1, int hp = 100);
    virtual ~Personagem();

    const string& getNome() const;
    int getLevel() const;
    int getHP() const;
    void setHP(int hp);

    virtual string tipo() const = 0;

    virtual int atacar(Personagem*) = 0;
    virtual int especial(Personagem*) = 0;
    virtual void supporte(Personagem*) = 0;

protected:
    string nome;
    int level;
    int hp;
};

#endif