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
        int larguraSprite = 0;
        int alturaSprite = 0;
        vector<Sprite> spritesSalvar;
        vector<string> linhas;
        string linha;

        while (getline(arquivo, linha)) {
            if(linha == "proxsprite" || linha == "fimsprite"){
                Sprite spriteSalvar = Sprite(linhas);
                linhas.clear();
                spritesSalvar.push_back(spriteSalvar);
            }else{
                larguraSprite = linha.length()-1;
                linhas.push_back(linha);
            };
        }
        sprites = SpriteAnimado(spritesSalvar);
        largura = larguraSprite;
        altura = sprites.getSprites()[sprites.getSprites().size()-1].getLinhas().size()-1;
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
    if(lado == "s" && (y+altura+1) < 40){
        y++;
    }
    if(lado == "w" && y > 0){
        y--;
    }
    if(lado == "a" && x > 0 ){
        x--;
    }
    if(lado == "d" && (x+largura+1) < 160){
        x++;
    }
};

void ObjetoDoJogo::atualizaSprite(){
    sprites.atualizarSpriteAtual();
}

void ObjetoDoJogo::setX(int numero){
    x = numero;
}

void ObjetoDoJogo::setY(int numero){
    y = numero;
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

bool ObjetoDoJogo::getAtivo(){
    return ativo;
}

int ObjetoDoJogo::getAltura(){
    return altura;
}

int ObjetoDoJogo::getLargura(){
    return largura;
}