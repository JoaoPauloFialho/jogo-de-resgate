#include "SpriteAnimado.h"
#include "Sprite.h"
#include <iostream>
#include <unistd.h>
using namespace std;

SpriteAnimado::SpriteAnimado(){
    spriteAtual = 0;
};

SpriteAnimado::SpriteAnimado(Sprite sprite1, Sprite sprite2){
    spriteAtual = 0;
    sprites[0] = sprite1;
    sprites[1] = sprite2;
}

void SpriteAnimado::desenharNaTela(int x, int y){
    while(1){
        for(int i =0; i < 2; i++){
            for(int j = 0; j < 3; j++){
                cout << sprites[i].getSprite()[j] << endl;
            }
            sleep(1);
            system("clear");
        }
    }
};

void SpriteAnimado::setSprites(Sprite lista[]){

};

void SpriteAnimado::trocarSpriteAtual(){
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

Sprite* SpriteAnimado::getSprites(){
    return sprites;
}
