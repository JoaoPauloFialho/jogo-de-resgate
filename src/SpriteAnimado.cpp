#include "SpriteAnimado.h"
#include "Sprite.h"
#include <iostream>
#include <unistd.h>
using namespace std;

SpriteAnimado::SpriteAnimado(){
    spriteAtual = 0;
};

SpriteAnimado::SpriteAnimado(vector<Sprite> spritesSalvar){
    spriteAtual = 0;
    sprites.push_back(spritesSalvar[0]);
    sprites.push_back(spritesSalvar[1]);
}

void SpriteAnimado::setSprites(vector<Sprite> spritesSalvar){
    spriteAtual = 0;
    sprites.push_back(spritesSalvar[0]);
    sprites.push_back(spritesSalvar[1]);
};

void SpriteAnimado::atualizarSpriteAtual(){
    if(spriteAtual == 1){
        spriteAtual = 0;
    }
    else{
        spriteAtual = 1;
    }
}

int SpriteAnimado::getSpriteAtual(){
    return spriteAtual;
}

vector<Sprite> SpriteAnimado::getSprites(){
    return sprites;
}
