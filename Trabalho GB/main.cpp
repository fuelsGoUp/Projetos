#include <iostream>
#include "Guerreiro.h"
#include "Mago.h"
#include "Forteiro.h"
#include "Salvar.h"
#include "Carregar.h"

using namespace std;

int main(){
    /*while(true){
        cout << "Bem vindo ao jogo de RPG!\n";
        cout << "1. Novo jogo\n";
        cout << "2. Carregar jogo\n";
        cout << "3. Sair\n";
        int escolha;
        cin >> escolha;
        if(escolha == 1){
            break;
        }
        if(escolha == 2){
            continuar = 1;
            break;
        }
    } função para carregar jogo, não filnalizada ainda
    */

    Personagem* personagens[3];

    personagens[0] = new Guerreiro("Arthur", 5);
    personagens[1] = new Mago("Gandalf", 4);
    personagens[2] = new Forteiro("Rubyorforb", 6);

    salvarJogo("salvo.txt", personagens, 3);

    int qtd = 0;

    Personagem** carregados = carregarJogo("salvo.txt", &qtd);

    cout << "carregados: " << qtd << " personagens\n";

    int personagemEscolhido = 0;
    while(true){
        cout << " escolha seu personagem: \n 1. Arthur \n 2. Gandalf \n 3. Rubyorforb \n";
        cin >> personagemEscolhido;
        if(personagemEscolhido >=1 && personagemEscolhido <=3){
            break;
        }
        else {
            cout << "Escolha Invalida. \n";
        }
    }

    int inimigo = 0;
    while(true){
        cout << " escolha seu opponente: \n 1. Arthur \n 2. Gandalf \n 3. Rubyorforb \n";
        cin >> inimigo;
        if(inimigo >=1 && inimigo <=3 && inimigo != personagemEscolhido){
            break;
        }
        else {
            cout << "Escolha Invalida. \n";
        }
    }
    personagemEscolhido -= 1;
    inimigo -= 1;

    while(true){
        cout << "Bem vindo ao menu!\n";
        cout << "1. Listar Personagens\n";
        cout << "2. atacar\n";
        cout << "3. especial\n";
        cout << "4. supporte\n";
        cout << "5. salvar jogo\n";
        cout << "6. carregar jogo\n";
        cout << "7. sair\n";
        int opc;
        cin >> opc;
        switch (opc){
            case 1:
                for(int i = 0; i<qtd; i++){
                    cout << carregados[i]->getNome() << " - " << carregados[i]->tipo() << " - HP: " << personagens[i]->getHP() << "\n";
                }
                break;
            case 2:
                carregados[personagemEscolhido]->atacar(carregados[inimigo]);
                break;
            case 3:
                carregados[personagemEscolhido]->especial(carregados[inimigo]);
                break;
            case 4:
                carregados[personagemEscolhido]->supporte(carregados[personagemEscolhido]);
                break;
            case 5:
                salvarJogo("salvo.txt", carregados, qtd);
                cout << "Jogo salvo!\n";
                break;
            case 6:
                delete[] carregados;
                carregados = carregarJogo("salvo.txt", &qtd);
                cout << "Jogo carregado!\n";
                break;
            case 7:
                cout << "Saindo...\n";
                return 0;
            default:
                cout << "Opção inválida!\n";
                break;
        }
    }
}