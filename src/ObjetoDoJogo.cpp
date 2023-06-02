#include <vector>
#include <iostream>
#include <fstream>
#include "ObjetoDoJogo.h"
#include "SpriteAnimado.h"
using namespace std;

ObjetoDoJogo::ObjetoDoJogo(){};

ObjetoDoJogo::ObjetoDoJogo(string caminhoDoArquivo,int numX, int numY){
    ifstream arquivo(caminhoDoArquivo);

    if (arquivo.is_open()) {
        vector<Sprite> spritesSalvar;
        vector<string> linhas;
        string linha;

        while (getline(arquivo, linha)) {
            if(linha == "proxsprite" || linha == "fimsprite"){
                Sprite spriteSalvar = Sprite(linhas);
                linhas.clear();
                spritesSalvar.push_back(spriteSalvar);
            }else{
                linhas.push_back(linha);
            };
        }
        sprites = SpriteAnimado(spritesSalvar);
        arquivo.close();
    } else {
        //lembrar de adicionar uma exceção aqui no futuro
    }
    x = numX;
    y = numY;
};

void ObjetoDoJogo::ativa(){ativo = true;};

void ObjetoDoJogo::desativa(){ativo = false;};

void ObjetoDoJogo::moveTo(string lado){
    if(lado == "d"){
        y = y+1;
    }
    if(lado == "a"){
        y = y-1;
    }
};

void ObjetoDoJogo::atualizaSprite(){
    sprites.atualizarSpriteAtual();
}

int ObjetoDoJogo::getX(){
    return x;
}

int ObjetoDoJogo::getY(){
    return y;
}

SpriteAnimado ObjetoDoJogo::getSprites(){
    return sprites;
}

void ObjetoDoJogo::setX(int numero){
    x = numero;
}

void ObjetoDoJogo::setY(int numero){
    y = numero;
}

bool ObjetoDoJogo::getAtivo(){
    return ativo;
}