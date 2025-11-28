#include "Salvar.h"
#include <fstream>

void salvarJogo(const char* arquivo, Personagem** lista, int qtd) {
    std::ofstream out(arquivo);
    if(!out.is_open()) return;

    for(int i = 0; i < qtd; i++){
        Personagem* p = lista[i];
        out << p->getNome() << " "
            << p->getLevel() << " "
            << p->getHP() << " "
            << p->tipo() << "\n";
    }
}