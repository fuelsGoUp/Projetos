#include "Carregar.h"
#include "Guerreiro.h"
#include "Mago.h"
#include "Forteiro.h"
#include <fstream>
#include <cstring>

using namespace std;

Personagem** carregarJogo(const char* arquivo, int* qtd) {
    *qtd = 0;
    ifstream in(arquivo);
    if(!in.is_open()) return nullptr;

    string s;
    while(getline(in, s)) (*qtd)++;

    if(*qtd == 0) return nullptr;

    in.clear();
    in.seekg(0);

    Personagem** lista = new Personagem*[*qtd];
    
    for(int i = 0; i<*qtd; i++){
        string nome, tipo;
        int level, hp;

        in >> nome >> level >> hp >> tipo;

        Personagem* p = nullptr;

        if(tipo == "Guerreiro") p = new Guerreiro(nome, level);
        else if(tipo == "Mago") p = new Mago(nome, level);
        else if(tipo == "Forteiro") p = new Forteiro(nome, level);

        if(p){
            p->setHP(hp);
            lista[i] = p;
        }
    }

    return lista;
}