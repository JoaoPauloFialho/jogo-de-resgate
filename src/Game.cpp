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
    for(int i=0; i < 30; i++){
        for(int j=0; j < 50; j++){
            tela[i][j] = ' ';
        }
    }
    for(int i = 0; i < objetos.size(); i++){
        ObjetoDoJogo obj = objetos[i];
        desenhar(obj);
    }
};

void Game::mostrar(){
    for(int i=0; i < 30; i++){
        for(int j=0; j < 50; j++){
            cout << tela[i][j];
        }
        cout<<endl;
    }
};

void Game::atualizar(string cmd){
    for(int i=0; i < 30; i++){
        for(int j=0; j < 50; j++){
            tela[i][j] = ' ';
        }
    }
    for(int i = 0; i < objetos.size(); i++){
        ObjetoDoJogo obj = objetos[i];
        if(obj.getMovel()){
            if(cmd == "x"){
                for(int i = 0; i < objetos.size(); i++){
                    ObjetoDoJogo objColisao = objetos[i];
                    if(obj.colideComObjeto(objColisao)){
                        //colidiu com alguma pessoa
                    }
                }
            }else if(cmd == "p"){}else if(cmd == "q"){
            }else{
                obj.moveTo(cmd);
            }
        }
        obj.atualizaSprite();
        desenhar(obj);
        objetos[i] = obj;
    }
}

void Game::desenhar(ObjetoDoJogo obj){
    int x = obj.getX();
    int y = obj.getY();
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
            tela[y+linhaSprite][x+indice] = linha[indice]; 
        }
    }
}

void Game::jogar(){
    string andar;
    inicializar();
    while(1){
        mostrar();
        cin >> andar;
        atualizar(andar);
        //system("clear");
    }
}