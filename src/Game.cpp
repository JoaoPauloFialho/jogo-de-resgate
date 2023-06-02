#include "Game.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

Game::Game(){};
Game::Game(vector<ObjetoDoJogo> objetosDoJogo){
    objetos = objetosDoJogo;
};

void Game::inicializar(){
    for(int i=0; i < 10; i++){
        for(int j=0; j < 100; j++){
            tela[i][j] = ' ';
        }
    }
    for(int i = 0; i < objetos.size(); i++){
        ObjetoDoJogo obj = objetos[i];
        desenhar(obj, obj.getX(), obj.getY());
    }
};

void Game::mostrar(){
    for(int i=0; i < 10; i++){
        for(int j=0; j < 100; j++){
            cout << tela[i][j];
        }
        cout<<endl;
    }
};

void Game::atualizar(string cmd){
    for(int i=0; i < 10; i++){
        for(int j=0; j < 100; j++){
            tela[i][j] = ' ';
        }
    }
    for(int i = 0; i < objetos.size(); i++){
        ObjetoDoJogo obj = objetos[i];
        if(obj.getAtivo()){
            obj.moveTo(cmd);
        }
        obj.atualizaSprite();
        desenhar(obj, obj.getX(), obj.getY());
        objetos[i] = obj;
    }
}

void Game::desenhar(ObjetoDoJogo obj, int x, int y){
    int spriteAtual = obj.getSprites().getSpriteAtual();
    SpriteAnimado sprites = obj.getSprites();
    vector<string> linhasDoSprite = sprites.getSprites()[spriteAtual].getLinhas();
    
    for(int linhaSprite = 0; linhaSprite < linhasDoSprite.size(); linhaSprite++){//pego cada linha do sprite
        string linha = linhasDoSprite[linhaSprite];
        //itero o tamanho da linha do sprite, na hora de salvar o X será o índice da linha do sprite já que
        //o mesmo possui 3 linhas de altura e o Y será o índice da iteração da largura da linha + o y, já que
        //o sprite varia de largura basicamente
        for(int indice = 0; indice < linha.length(); indice++){
            //int linha = x+linhaSprite;
            //int coluna = indice+y;
            tela[x+linhaSprite][indice+y] = linha[indice]; 
        }
    }
}