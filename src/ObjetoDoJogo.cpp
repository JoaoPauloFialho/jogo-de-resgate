#include <vector>
#include <iostream>
#include <fstream>
#include "ObjetoDoJogo.h"
#include "SpriteAnimado.h"
#include "constantes.h"
using namespace std;

ObjetoDoJogo::ObjetoDoJogo(){};

ObjetoDoJogo::ObjetoDoJogo(string caminhoDoArquivo,int numX, int numY){
    sprites = SpriteAnimado(caminhoDoArquivo);
    largura = sprites.getLargura();
    altura = sprites.getAltura();
    x = numX;
    y = numY;
    ativo = true;
};

void ObjetoDoJogo::ativa(){ativo = true;};

void ObjetoDoJogo::desativa(){ativo = false;};

void ObjetoDoJogo::moveTo(string lado){
    if(lado == "s" && (y+altura+1) < jogo::YINICIALBASE+1) y+= jogo::DESLOCAMENTO;//+1 pois quero que o helicoptero fique no mínimo
    if(lado == "w" && y > 0) y-= jogo::DESLOCAMENTO;                              //na altura da primeira linha da base (sobrepondo primeira linha)
    if(lado == "a" && x > 0 ) x-= jogo::DESLOCAMENTO;
    if(lado == "d" && (x+largura+1) < jogo::LARGURAJOGO) x+= jogo::DESLOCAMENTO;
};

void ObjetoDoJogo::atualizar(){
    sprites.atualizar();
};

void ObjetoDoJogo::inicializar(){};

bool ObjetoDoJogo::colideComObjeto(ObjetoDoJogo obj){
    if((obj.getY() >= y && obj.getY() <= y+altura) || (y >= obj.getY() && y<= obj.getY() + obj.getAltura())){
        if((obj.getX() >= x && obj.getX() <= x+largura) || (x >= obj.getX() && x<= obj.getX() + obj.getLargura())){
            return true; //tem 2 ifs pois eu preciso checar se o obj1 está sobre o obj2 ou se o obj2 está sobre obj1
        }                //isso acontece pois tem essas 2 possibilidades para que o obj de analise esteja colidindo
    }                    //com o outro
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