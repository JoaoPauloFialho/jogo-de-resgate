#include <iostream>
#include "ObjetoDoJogo.h"
#include "SpriteAnimado.h"

ObjetoDoJogo::ObjetoDoJogo(){};

ObjetoDoJogo::ObjetoDoJogo(int numX, int numY){
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