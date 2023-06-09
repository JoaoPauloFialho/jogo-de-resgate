#include "Fase.h"
#include "Helicoptero.h"
#include "Base.h"
#include "SpriteAnimado.h"
#include "constantes.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

Fase::Fase(){};
Fase::Fase(vector<ObjetoDoJogo> objetosDoJogo){
    base = Base("sprites/base.txt", jogo::XINICIALBASE, jogo::YINICIALBASE);
    helicoptero = Helicoptero("sprites/helicoptero.txt",jogo::XINICIALHELICOPTERO , jogo::YINICIALHELICOPTERO);
    background = SpriteAnimado("sprites/background1.txt");
    objetos = objetosDoJogo;
    executando = true;
};

void Fase::inicializar(){
    for(int i=0; i < jogo::ALTURAJOGO; i++){
        for(int j=0; j < jogo::LARGURAJOGO; j++){
            tela[i][j] = ' ';
        }
    }
    desenhar(1,1,background.getSpriteAtual());
    for(int i = 0; i < objetos.size(); i++){
        ObjetoDoJogo obj = objetos[i];
        desenhar(obj);
    }
    desenhar(base);
    desenhar(helicoptero);
};


void Fase::mostrar(){
    for(int i=0; i < jogo::ALTURAJOGO; i++){
        for(int j=0; j < jogo::LARGURAJOGO; j++){
            cout << tela[i][j];
        }
        cout<<endl;
    }
};

void Fase::atualizar(){
    for(int i=0; i < jogo::ALTURAJOGO; i++){
        for(int j=0; j < jogo::LARGURAJOGO; j++){
            tela[i][j] = ' ';
        }
    }
    base.atualizar();
    helicoptero.atualizar();
    background.atualizar();
    desenhar(1,1,background.getSpriteAtual());
    desenhar(base);
    desenhar(helicoptero);
    for(int i = 0; i < objetos.size(); i++){
        ObjetoDoJogo *obj = &objetos[i];
        if(obj->getAtivo()){
            obj->atualizar();
            desenhar(*obj);
        }
    }
    if(base.getPessoasResgatadas().size() == jogo::PESSOASNIVELFACIL){
        executando = false;
    }
}

void Fase::desenhar(ObjetoDoJogo obj){
    int x = obj.getX();
    int y = obj.getY();
    SpriteAnimado sprites = obj.getSprites();
    vector<string> linhasDoSprite = sprites.getSpriteAtual().getLinhas();
    
    for(int linhaSprite = 0; linhaSprite < linhasDoSprite.size(); linhaSprite++){
        string linha = linhasDoSprite[linhaSprite];
        for(int indice = 0; indice < linha.length(); indice++){
            tela[y+linhaSprite][x+indice] = linha[indice]; 
        }
    }
}

void Fase::desenhar(int y, int x,Sprite spr){
    vector<string> linhasDoSprite = spr.getLinhas();
    for(int linhaSprite = 0; linhaSprite < linhasDoSprite.size(); linhaSprite++){
       string linha = linhasDoSprite[linhaSprite];
       for(int indice = 0; indice < linha.length(); indice++){
           tela[y+linhaSprite][x+indice] = linha[indice]; 
       }
    }
}

void Fase::jogar(){
    string cmd;
    inicializar();
    while(executando){
        mostrar();
        cin >> cmd;
        if(cmd == "x"){
        for(int i = 0; i < objetos.size(); i++){
            ObjetoDoJogo* objColisao = &objetos[i];
            if(!objColisao->getObstaculo()){
                if(helicoptero.colideComObjeto(*objColisao) && helicoptero.getQntPessoas()+1 <= helicoptero.getCapacidadeMax()){ 
                    objColisao->desativa();
                    helicoptero+*objColisao;
                }
            }
            }
        if(helicoptero.getX() >= base.getX() && helicoptero.getX()+helicoptero.getLargura()<= base.getX() + base.getLargura()){
            if(helicoptero.getY()+helicoptero.getAltura() == base.getY()){
                if(helicoptero.getPessoasResgatadas().size() > 0){
                    ObjetoDoJogo pessoaResgatada = --helicoptero;
                    base+pessoaResgatada;
                }
            }
        }
        }else if(cmd == "p"){}
        else if(cmd == "q"){
            executando = false;
        }else{
            helicoptero.moveTo(cmd);
            for(int i = 0; i < objetos.size(); i++){
                ObjetoDoJogo obj = objetos[i];
                if(helicoptero.colideComObjeto(obj) && obj.getObstaculo()){
                    executando = false;
                }
            }
        }
        atualizar();
        system("clear");
    }
    system("clear");
}