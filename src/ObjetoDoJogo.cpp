#include <iostream>
#include "ObjetoDoJogo.h"
#include "SpriteAnimado.h"

ObjetoDoJogo::ObjetoDoJogo(){};

void ObjetoDoJogo::ativa(){ativo = true;};

void ObjetoDoJogo::desativa(){ativo = false;};

void ObjetoDoJogo::moveTo(){};

void ObjetoDoJogo::atualizaSprite(){
    if(sprites.getSpriteAtual() == 0){
        sprites.trocarSpriteAtual();
    }
    else{
        sprites.trocarSpriteAtual();
    }
}

void ObjetoDoJogo::desenharSla(){
    sprites.desenharNaTela(1, 2);
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