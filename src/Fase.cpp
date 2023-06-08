#include "Fase.h"
#include "Helicoptero.h"
#include "SpriteMensagemPause.h"
#include "Base.h"
#include "constantes.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

Fase::Fase(){};
Fase::Fase(vector<ObjetoDoJogo> objetosDoJogo){
    base = Base("sprites/base.txt", jogo::XINICIALBASE, jogo::YINICIALBASE);
    helicoptero = Helicoptero("sprites/helicoptero.txt",jogo::XINICIALHELICOPTERO , jogo::YINICIALHELICOPTERO);
    objetos = objetosDoJogo;
    executando = true;
};

void Fase::inicializar(){
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

void Fase::desenharEntidade(ObjetoDoJogo obj){
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

void Fase::desenharEntidade(int y, int x,Sprite spr){
    vector<string> linhasDoSprite = spr.getLinhas();
    
    for(int linhaSprite = 0; linhaSprite < linhasDoSprite.size(); linhaSprite++){
        string linha = linhasDoSprite[linhaSprite];
        cout << linha << endl;
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