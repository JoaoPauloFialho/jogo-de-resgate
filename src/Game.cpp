#include "Game.h"
#include "Helicoptero.h"
#include "Base.h"
#include "constantes.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

Game::Game(){};
Game::Game(vector<ObjetoDoJogo> objetosDoJogo){
    base = Base("sprites/base.txt", 0, jogo::YINICIALBASE);
    helicoptero = Helicoptero("sprites/helicoptero.txt",0 , jogo::YINICIALHELICOPTERO);
    objetos = objetosDoJogo;
    executando = true;
};

void Game::inicializar(){
    for(int i=0; i < jogo::ALTURAJOGO; i++){
        for(int j=0; j < jogo::LARGURAJOGO; j++){
            tela[i][j] = ' ';
        }
    }
    for(int i = 0; i < objetos.size(); i++){
        ObjetoDoJogo obj = objetos[i];
        desenharEntidade(obj);
    }
    desenharEntidade(base);
    desenharEntidade(helicoptero);
};

void Game::mostrar(){
    for(int i=0; i < jogo::ALTURAJOGO; i++){
        for(int j=0; j < jogo::LARGURAJOGO; j++){
            cout << tela[i][j];
        }
        cout<<endl;
    }
};

void Game::atualizar(string cmd){
    for(int i=0; i < jogo::ALTURAJOGO; i++){
        for(int j=0; j < jogo::LARGURAJOGO; j++){
            tela[i][j] = ' ';
        }
    }
    if(cmd == "x"){
        for(int i = 0; i < objetos.size(); i++){
            ObjetoDoJogo* objColisao = &objetos[i];
            cout << helicoptero.getCapacidadeMax() << endl;
            cout << helicoptero.getQntPessoas() << endl;
            if(helicoptero.colideComObjeto(*objColisao) && helicoptero.getQntPessoas()+1 <= helicoptero.getCapacidadeMax()){ 
                objColisao->desativa();
                helicoptero+*objColisao;
                }
            }
        if(helicoptero.getX() + helicoptero.getX() <= base.getX() + base.getLargura()){
            if(helicoptero.getPessoasResgatadas().size() > 0){
                ObjetoDoJogo pessoaResgatada = --helicoptero;
                base+pessoaResgatada;
            }
        }
    }else if(cmd == "p"){

    }else if(cmd == "q"){
        executando = false;
    }else{
        helicoptero.moveTo(cmd);
    }
    base.atualiza();
    helicoptero.atualiza();
    desenharEntidade(base);
    desenharEntidade(helicoptero);
    for(int i = 0; i < objetos.size(); i++){
        ObjetoDoJogo obj = objetos[i];
        if(obj.getAtivo()){
            obj.atualiza();
            desenharEntidade(obj);
        }
        objetos[i] = obj;
    }
    if(base.getPessoasResgatadas().size() == jogo::PESSOASNIVELFACIL){
        executando = false;
    }
}

void Game::desenharEntidade(ObjetoDoJogo obj){
    int x = obj.getX();
    int y = obj.getY();
    int spriteAtual = obj.getSprites().getSpriteAtual();
    SpriteAnimado sprites = obj.getSprites();
    vector<string> linhasDoSprite = sprites.getSprites()[spriteAtual].getLinhas();
    
    for(int linhaSprite = 0; linhaSprite < linhasDoSprite.size(); linhaSprite++){
        string linha = linhasDoSprite[linhaSprite];
        for(int indice = 0; indice < linha.length(); indice++){
            tela[y+linhaSprite][x+indice] = linha[indice]; 
        }
    }
}

void Game::jogar(){
    string andar;
    inicializar();
    while(executando){
        mostrar();
        cin >> andar;
        atualizar(andar);
        //system("clear");
    }
    system("clear");
}