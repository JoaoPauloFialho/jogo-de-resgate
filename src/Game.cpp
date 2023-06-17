#include "Fase.hpp"
#include "SpriteAnimado.hpp"
#include "Pessoa.hpp"
#include "Item.hpp"
#include "GameBase.hpp"
#include "Obstaculo.hpp"
#include "Sprite.hpp"
#include "Base.hpp"
#include "Game.hpp"
#include "Helicoptero.hpp"
#include "Game.hpp"
#include <iostream>
using namespace std;

Game::Game(){};

void Game::inicializar(){};

int Game::faseAtual = 1;

void Game::atualizar(){};

int Game::getFaseAtual() { return faseAtual; };

void Game::rodar()
{
    while (true)
    {
        if (faseAtual == 4)break;
        if (faseAtual == 1){
            vector<ObjetoDoJogo *> objetosDoJogo;
            Item *fuel = new Item("sprites/fuel.txt", 90, 15);
            Obstaculo *predio = new Obstaculo("sprites/predio1.txt", 40);
            Obstaculo *carro = new Obstaculo("sprites/carro1.txt", 77);
            Obstaculo *fogo1 = new Obstaculo("sprites/fogo.txt", 23);
            Obstaculo *fogo2 = new Obstaculo("sprites/fogo.txt", 80, jogo::ALTURAJOGO - carro->getAltura() - 2);
            Obstaculo *fogo3 = new Obstaculo("sprites/fogo.txt", 86);
            Pessoa *pes1 = new Pessoa("sprites/pessoa.txt", 42, 15);
            Pessoa *pes2 = new Pessoa("sprites/pessoa.txt", 70, 15);
            Pessoa *pes3 = new Pessoa("sprites/pessoa.txt", 95);
            Pessoa *pes4 = new Pessoa("sprites/pessoa.txt", 98);
            Pessoa *pes5 = new Pessoa("sprites/pessoa.txt", 127, 22);
            Pessoa *pes6 = new Pessoa("sprites/pessoa.txt", 34);
            Obstaculo *onibus = new Obstaculo("sprites/onibus1.txt", 105);
            Obstaculo *fogo4 = new Obstaculo("sprites/fogo.txt", 107, jogo::ALTURAJOGO - onibus->getAltura() - 2);
            Obstaculo *fogo5 = new Obstaculo("sprites/fogo.txt", 115, jogo::ALTURAJOGO - onibus->getAltura());
            Obstaculo *fogo6 = new Obstaculo("sprites/fogo.txt", 120, jogo::ALTURAJOGO - onibus->getAltura() - 3);
            Obstaculo *fogo7 = new Obstaculo("sprites/fogo.txt", 124);
            objetosDoJogo.push_back(predio);
            objetosDoJogo.push_back(fuel);
            objetosDoJogo.push_back(carro);
            objetosDoJogo.push_back(pes1);
            objetosDoJogo.push_back(pes2);
            objetosDoJogo.push_back(pes3);
            objetosDoJogo.push_back(pes4);
            objetosDoJogo.push_back(pes5);
            objetosDoJogo.push_back(pes6);
            objetosDoJogo.push_back(onibus);
            objetosDoJogo.push_back(fogo1);
            objetosDoJogo.push_back(fogo2);
            objetosDoJogo.push_back(fogo3);
            objetosDoJogo.push_back(fogo4);
            objetosDoJogo.push_back(fogo5);
            objetosDoJogo.push_back(fogo6);
            objetosDoJogo.push_back(fogo7);
            Fase fase = Fase(objetosDoJogo, "sprites/background1.txt");
            bool venceu = fase.jogar();
            if(venceu){
                faseAtual = 2;
            }
            continue;
        }
        else if (faseAtual == 2)
        {
            vector<ObjetoDoJogo *> objetosDoJogo;
            Item *fuel1 = new Item("sprites/fuel.txt", 94, 15);
            Item *fuel2 = new Item("sprites/fuel.txt", 50, 10);
            Obstaculo *carro1 = new Obstaculo("sprites/carro1.txt", 30);
            Obstaculo *carro2 = new Obstaculo("sprites/carro1.txt", 56);
            Obstaculo *fogo1 = new Obstaculo("sprites/fogo.txt", 30, jogo::ALTURAJOGO - carro1->getAltura() - 1);
            Obstaculo *fogo2 = new Obstaculo("sprites/fogo.txt", 36, jogo::ALTURAJOGO - carro1->getAltura() - 2);
            Obstaculo *fogo3 = new Obstaculo("sprites/fogo.txt", 57, jogo::ALTURAJOGO - carro1->getAltura() - 2);
            Obstaculo *fogo4 = new Obstaculo("sprites/fogo.txt", 62);
            Pessoa *pes1 = new Pessoa("sprites/pessoa.txt", 45);
            Pessoa *pes2 = new Pessoa("sprites/pessoa.txt", 48);
            Pessoa *pes3 = new Pessoa("sprites/pessoa.txt", 72);
            Obstaculo *predio = new Obstaculo("sprites/predio2.txt", 80);
            Pessoa *pes4 = new Pessoa("sprites/pessoa.txt", 98);
            Pessoa *pes5 = new Pessoa("sprites/pessoa.txt", 95);
            Pessoa *pes6 = new Pessoa("sprites/pessoa.txt", 127, 22);
            Obstaculo *onibus = new Obstaculo("sprites/onibus1.txt", 105);
            Obstaculo *fogo7 = new Obstaculo("sprites/fogo.txt", 107, jogo::ALTURAJOGO - onibus->getAltura() - 2);
            Obstaculo *fogo8 = new Obstaculo("sprites/fogo.txt", 115, jogo::ALTURAJOGO - onibus->getAltura());
            Obstaculo *fogo9 = new Obstaculo("sprites/fogo.txt", 120, jogo::ALTURAJOGO - onibus->getAltura() - 3);
            Obstaculo *fogo10 = new Obstaculo("sprites/fogo.txt", 80, jogo::ALTURAJOGO - predio->getAltura() + 13);
            Obstaculo *fogo11 = new Obstaculo("sprites/fogo.txt", 83, jogo::ALTURAJOGO - predio->getAltura() + 9);
            Obstaculo *fogo12 = new Obstaculo("sprites/fogo.txt", 84, jogo::ALTURAJOGO - predio->getAltura() + 4);
            Obstaculo *fogo13 = new Obstaculo("sprites/fogo.txt", 82, jogo::ALTURAJOGO - predio->getAltura() + 1);
            objetosDoJogo.push_back(predio);
            objetosDoJogo.push_back(fuel1);
            objetosDoJogo.push_back(fuel2);
            objetosDoJogo.push_back(carro1);
            objetosDoJogo.push_back(carro2);
            objetosDoJogo.push_back(pes1);
            objetosDoJogo.push_back(pes2);
            objetosDoJogo.push_back(pes3);
            objetosDoJogo.push_back(pes4);
            objetosDoJogo.push_back(pes5);
            objetosDoJogo.push_back(pes6);
            objetosDoJogo.push_back(onibus);
            objetosDoJogo.push_back(fogo1);
            objetosDoJogo.push_back(fogo2);
            objetosDoJogo.push_back(fogo3);
            objetosDoJogo.push_back(fogo4);
            objetosDoJogo.push_back(fogo7);
            objetosDoJogo.push_back(fogo8);
            objetosDoJogo.push_back(fogo9);
            objetosDoJogo.push_back(fogo10);
            objetosDoJogo.push_back(fogo11);
            objetosDoJogo.push_back(fogo12);
            objetosDoJogo.push_back(fogo13);
            Fase fase = Fase(objetosDoJogo, "sprites/background1.txt");
            bool venceu = fase.jogar();
            if(venceu){
                faseAtual = 3;
            }
            continue;
        }else if(faseAtual == 3){
            vector<ObjetoDoJogo *> objetosDoJogo;
            Item *fuel1 = new Item("sprites/fuel.txt", 94, 15);
            Obstaculo *carro1 = new Obstaculo("sprites/carro1.txt", 30);
            Obstaculo *carro2 = new Obstaculo("sprites/carro1.txt", 56);
            Obstaculo *fogo1 = new Obstaculo("sprites/fogo.txt", 30, jogo::ALTURAJOGO - carro1->getAltura() - 1);
            Obstaculo *fogo2 = new Obstaculo("sprites/fogo.txt", 36, jogo::ALTURAJOGO - carro1->getAltura() - 2);
            Obstaculo *fogo3 = new Obstaculo("sprites/fogo.txt", 57, jogo::ALTURAJOGO - carro1->getAltura() - 2);
            Obstaculo *fogo4 = new Obstaculo("sprites/fogo.txt", 62);
            Pessoa *pes1 = new Pessoa("sprites/pessoa.txt", 45);
            Pessoa *pes2 = new Pessoa("sprites/pessoa.txt", 48);
            Pessoa *pes3 = new Pessoa("sprites/pessoa.txt", 72);
            Obstaculo *arvore = new Obstaculo("sprites/arvore1.txt", 82);
            Pessoa *pes4 = new Pessoa("sprites/pessoa.txt", 86, jogo::ALTURAJOGO-arvore->getAltura()-2);
            Pessoa *pes5 = new Pessoa("sprites/pessoa.txt", 95);
            Pessoa *pes6 = new Pessoa("sprites/pessoa.txt", 127, 20);
            Obstaculo *cabana = new Obstaculo("sprites/cabana1.txt", 107);
            Obstaculo *fogo7 = new Obstaculo("sprites/fogo.txt", 107, jogo::ALTURAJOGO - cabana->getAltura() - 2);
            Obstaculo *fogo8 = new Obstaculo("sprites/fogo.txt", 115, jogo::ALTURAJOGO - cabana->getAltura());
            Obstaculo *fogo9 = new Obstaculo("sprites/fogo.txt", 120, jogo::ALTURAJOGO - cabana->getAltura() - 3);
            Obstaculo *fogo10 = new Obstaculo("sprites/fogo.txt", 82, jogo::ALTURAJOGO - arvore->getAltura() + 7);
            Obstaculo *fogo11 = new Obstaculo("sprites/fogo.txt", 86, jogo::ALTURAJOGO - arvore->getAltura() + 9);
            objetosDoJogo.push_back(arvore);
            objetosDoJogo.push_back(fuel1);
            objetosDoJogo.push_back(carro1);
            objetosDoJogo.push_back(carro2);
            objetosDoJogo.push_back(pes1);
            objetosDoJogo.push_back(pes2);
            objetosDoJogo.push_back(pes3);
            objetosDoJogo.push_back(pes4);
            objetosDoJogo.push_back(pes5);
            objetosDoJogo.push_back(pes6);
            objetosDoJogo.push_back(cabana);
            objetosDoJogo.push_back(fogo1);
            objetosDoJogo.push_back(fogo2);
            objetosDoJogo.push_back(fogo3);
            objetosDoJogo.push_back(fogo4);
            objetosDoJogo.push_back(fogo7);
            objetosDoJogo.push_back(fogo8);
            objetosDoJogo.push_back(fogo9);
            objetosDoJogo.push_back(fogo10);
            objetosDoJogo.push_back(fogo11);
            Fase fase = Fase(objetosDoJogo, "sprites/background3.txt");
            bool venceu = fase.jogar();
            if(venceu){
                faseAtual = 4;
            }
            continue;
        };
    }
};