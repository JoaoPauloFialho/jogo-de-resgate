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

int Game::getFaseAtual(){return faseAtual;};
    
void Game::rodar(){
    //while(true){
    //    int escolha;
        //cin >> escolha
        //if(escolha == 1){
            vector<ObjetoDoJogo*> objetosDoJogo;
            Item* fuel = new Item("sprites/fuel.txt", 90, 15);
            Obstaculo* predio = new Obstaculo("sprites/predio1.txt",40);
            Obstaculo* carro = new Obstaculo("sprites/carro1.txt", 79);
            Obstaculo* fogo1 = new Obstaculo("sprites/fogo.txt", 26);
            Obstaculo* fogo2 = new Obstaculo("sprites/fogo.txt", 82, jogo::ALTURAJOGO-carro->getAltura()-2);
            Obstaculo* fogo3 = new Obstaculo("sprites/fogo.txt", 88);
            Pessoa* pes1 = new Pessoa("sprites/pessoa.txt",42, 15);
            Pessoa* pes2 = new Pessoa("sprites/pessoa.txt",70, 15);
            Pessoa* pes3 = new Pessoa("sprites/pessoa.txt",95);
            Pessoa* pes4 = new Pessoa("sprites/pessoa.txt",98);
            Pessoa* pes5 = new Pessoa("sprites/pessoa.txt",127, 22);
            Pessoa* pes6 = new Pessoa("sprites/pessoa.txt",34);
            Obstaculo* onibus = new Obstaculo("sprites/onibus1.txt", 105);
            Obstaculo* fogo4 = new Obstaculo("sprites/fogo.txt", 107, jogo::ALTURAJOGO-onibus->getAltura()-2);
            Obstaculo* fogo5 = new Obstaculo("sprites/fogo.txt", 115, jogo::ALTURAJOGO-onibus->getAltura());
            Obstaculo* fogo6 = new Obstaculo("sprites/fogo.txt", 120, jogo::ALTURAJOGO-onibus->getAltura()-3);
            Obstaculo* fogo7 = new Obstaculo("sprites/fogo.txt", 124);
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
            fase.jogar();
        //}
    //}
};