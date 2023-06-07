#include <vector>
#include <iostream>
#include <fstream>
#include "ObjetoDoJogo.h"
#include "SpriteAnimado.h"
#include "constantes.h"
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
    ativo = true;
    //obstaculo = true;
};

void ObjetoDoJogo::ativa(){ativo = true;};

void ObjetoDoJogo::desativa(){ativo = false;};

void ObjetoDoJogo::moveTo(string lado){
    if(lado == "s" && (y+altura+1) < jogo::YINICIALBASE+1) y+= jogo::DESLOCAMENTO;//+1 pois quero que o helicoptero fique no mínimo
    if(lado == "w" && y > 0) y-= jogo::DESLOCAMENTO;                              //na altura da primeira linha da base (sobrepondo primeira linha)
    if(lado == "a" && x > 0 ) x-= jogo::DESLOCAMENTO;
    if(lado == "d" && (x+largura+1) < jogo::LARGURAJOGO) x+= jogo::DESLOCAMENTO;
};

void ObjetoDoJogo::atualiza(){
    sprites.atualizarSpriteAtual();
};
//1 s            z   
//2 s          s z   
//3 s z        s z     
//4 s z        s z     
//5              z
//6
//7

bool ObjetoDoJogo::colideComObjeto(ObjetoDoJogo obj){
    //        y <= obj.y <= y + altura (primeiro caso de colisão)
    //        obj.y  <= y <= obj.y + obj.altura
    if((obj.getY() >= y && obj.getY() <= y+altura) || (y >= obj.getY() && y<= obj.getY() + obj.getAltura())){
        if((obj.getX() >= x && obj.getX() <= x+largura) || (x >= obj.getX() && x<= obj.getX() + obj.getLargura())){
            return true;
        }
    } 
        
    //basicamente checo se o x <= obj.x <= x+largura e y <= obj.y <= y+largura
    //basicamente checo se o obj.x <= x <= obj.x+obj.largura
    //isso aqui só funciona para objetos menores que o helicoptero
    //if(
    //    (obj.getY() >= y && obj.getY() <= y+altura && x <= obj.getX() && obj.getX() <= x+largura)||
    //    (obj.getY() <= y && obj.getY()+obj.getAltura() <= y && obj.getX() <= x && obj.getX()+obj.getLargura() <= x )
    //) return true;
    return false;
};

void ObjetoDoJogo::setX(int numero){
    x = numero;
};

void ObjetoDoJogo::setY(int numero){
    y = numero;
};

int ObjetoDoJogo::getX(){
    return x;
};

int ObjetoDoJogo::getY(){
    return y;
};

SpriteAnimado ObjetoDoJogo::getSprites(){
    return sprites;
};

bool ObjetoDoJogo::getObstaculo(){
    return obstaculo;
}

bool ObjetoDoJogo::getAtivo(){
    return ativo;
};

int ObjetoDoJogo::getAltura(){
    return altura;
};

int ObjetoDoJogo::getLargura(){
    return largura;
};