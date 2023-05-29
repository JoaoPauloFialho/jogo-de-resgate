#include <iostream>
#include "Sprite.h"
using namespace std;

Sprite::Sprite(){}
string* Sprite::getSprite(){ 
    return sprite;
    };
void Sprite::setSprites(string linha1, string linha2, string linha3){
    sprite[0] = linha1;
    sprite[1] = linha2;
    sprite[2] = linha3;
};