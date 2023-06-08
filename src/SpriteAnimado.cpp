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
    for(int i = 0; i < spritesSalvar.size(); i ++){
        sprites.push_back(spritesSalvar[i]);
    }
}

void SpriteAnimado::setSprites(vector<Sprite> spritesSalvar){
    spriteAtual = 0;
    for(int i = 0; i < spritesSalvar.size(); i ++){
        sprites.push_back(spritesSalvar[i]);
    }
};

void SpriteAnimado::atualizar(){
    if(spriteAtual == sprites.size()-1){
        spriteAtual = 0;
    }
    else{
        spriteAtual++;
    }
}

void SpriteAnimado::inicializar(){};

int SpriteAnimado::getSpriteAtual(){
    return spriteAtual;
}

vector<Sprite> SpriteAnimado::getSprites(){
    return sprites;
}
