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
#include "SonsMenu.hpp"
#include "Game.hpp"
#include "constantes.hpp"
#include "utils.hpp"
#include <iostream>
#include <vector>
using namespace std;

Game::Game(){
    nomeJogo = SpriteAnimado("sprites/nomejogo.txt");
    opcaoAtual = 0;
    faseAtual = 0;
};

void Game::inicializar(){
    for(int i = 0; i < jogo::ALTURATELA; i++){
        for(int j = 0; j < jogo::LARGURATELA; j++){
            tela[i][j] = " ";
        }
    };
    opcoes.push_back("Novo Jogo");
    opcoes.push_back("Controles");
    opcoes.push_back("Sair");
    desenhar(0, (jogo::LARGURAJOGO/2)-(nomeJogo.getLargura()/2), nomeJogo);

    int indiceAtualIteracao = 0;
    for(int i = jogo::ALTURATELA/2; i < jogo::ALTURATELA/2+opcoes.size(); i++){
        string opcao = opcoes[indiceAtualIteracao];
        if(opcaoAtual == indiceAtualIteracao){
            opcao = "----> " + opcao +" <----";
        }
        for(int j = 0; j < opcao.size(); j++){
            //essa divisao é para que as strings fiquem simetricamente alinhadas
            //com essa conta elas se alinharão de acordo com o centro da tela e o seu próprio centro
            //mesma lógica que usei na hora de desenhar o nomeJogo ali em cima ^
            tela[i][j+(jogo::LARGURAJOGO/2)-(opcao.size()/2)] = opcao[j];
        }
        indiceAtualIteracao++;
    }
};

void Game::atualizar(){
    for(int i = 0; i < jogo::ALTURATELA; i++){
        for(int j = 0; j < jogo::LARGURATELA; j++){
            tela[i][j] = " ";
        }
    };
    desenhar(0, (jogo::LARGURAJOGO/2)-(nomeJogo.getLargura()/2), nomeJogo);

    if(int i = util::achaItemEmVetor(opcoes, "Continuar"); i != -1){
        opcoes.erase(opcoes.begin()+i);
    };
    if(faseAtual != 0){
        opcoes.insert(opcoes.begin(), "Continuar");
    };

    int indiceAtualIteracao = 0;
    for(int i = jogo::ALTURATELA/2; i < jogo::ALTURATELA/2+opcoes.size(); i++){
        string opcao = opcoes[indiceAtualIteracao];
        if(opcaoAtual == indiceAtualIteracao){
            if(opcao == "Continuar"){
                opcao = "----> " + opcao + " (Nível " + to_string(faseAtual) + " )" +" <----";
            }else{
                opcao = "----> " + opcao +" <----";
            }
        }
        for(int j = 0; j < opcao.size(); j++){
            //essa divisao é para que as strings fiquem simetricamente alinhadas
            //com essa conta elas se alinharão de acordo com o centro da tela e o seu próprio centro
            //mesma lógica que usei na hora de desenhar o nomeJogo ali em cima ^
            tela[i][j+(jogo::LARGURAJOGO/2)-(opcao.size()/2)] = opcao[j];
        }
        indiceAtualIteracao++;
    }
};

void Game::desenhar(int y, int x,SpriteAnimado spr){
    vector<string> linhasDoSprite = spr.getSpriteAtual().getLinhas();
    for(int linhaSprite = 0; linhaSprite < linhasDoSprite.size(); linhaSprite++){
       string linha = linhasDoSprite[linhaSprite];
       for(int indice = 0; indice < linha.length(); indice++){
           tela[y+linhaSprite][x+indice] = linha[indice]; 
       }
    }
}

void Game::mostrar(){
    for(int i = 0; i < jogo::ALTURATELA; i++){
        for(int j = 0; j < jogo::LARGURATELA; j++){
            cout << tela[i][j];
        }
    };
}


int Game::getFaseAtual() { return faseAtual; };

void Game::rodar()
{
    inicializar();
    while (true){
        system("clear");
        mostrar();
        string comando;
        getline(cin, comando);
        if(comando == "w"){
            if(opcaoAtual != 0){
                opcaoAtual--;
            }else{
                opcaoAtual=opcoes.size()-1;
            }
            jogo::moverMenu->play();
        }
        if(comando == "s"){
            if(opcaoAtual<opcoes.size()-1){
                opcaoAtual++;
            }else{
                opcaoAtual=0;
            }
            jogo::moverMenu->play();
        }
        if(comando == "" || comando == "x"){
            if(opcoes[opcaoAtual] == "Novo Jogo" ){
                faseAtual = 1;
            };
            if(opcoes[opcaoAtual] == "Sair"){
                break;
            };
            if(opcoes[opcaoAtual] == "Controles"){
                string comando;
                SpriteAnimado controles("sprites/comandos.txt");
                desenhar(jogo::ALTURATELA/2, (jogo::LARGURAJOGO/2)-(controles.getLargura()/2)-10, controles);
                system("clear");
                mostrar();
                getline(cin, comando);
                atualizar();
                continue;
            };
            if (faseAtual == 1){
                vector<ObjetoDoJogo *> objetosDoJogo;
                Item *fuel = new Item("sprites/fuel.txt", 90, 15);
                Item *fuel2 = new Item("sprites/fuel.txt", 33, 20);
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
                objetosDoJogo.push_back(fuel2);
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
                Fase fase = Fase(objetosDoJogo, "sprites/background1.txt", "sprites/mensagemfase1.txt" , "sounds/musicafase1.mp3");
                bool venceu = fase.jogar();
                if(venceu){
                    faseAtual = 2;
                };
            }
            if (faseAtual == 2)
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
                Fase fase = Fase(objetosDoJogo, "sprites/background1.txt", "sprites/mensagemfase2.txt" , "sounds/musicafase1.mp3");
                bool venceu = fase.jogar();
                if(venceu){
                    faseAtual = 3;
                };
            }if(faseAtual == 3){
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
                Pessoa *pes4 = new Pessoa("sprites/pessoa.txt", 86, jogo::ALTURAJOGO-arvore->getAltura()-3);
                Pessoa *pes5 = new Pessoa("sprites/pessoa.txt", 98);
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
                Fase fase = Fase(objetosDoJogo, "sprites/background3.txt", "sprites/mensagemfase3.txt" , "sounds/musicafase1.mp3");
                bool venceu = fase.jogar();
                if(venceu){
                    faseAtual = 0;
                }
            };
        }
        atualizar();
    }
};