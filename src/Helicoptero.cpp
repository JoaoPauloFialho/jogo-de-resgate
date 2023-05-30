#include "Helicoptero.h"


Helicoptero::Helicoptero(){
    Sprite sprite1 = Sprite();
    sprite1.setSprites("   (-----)", " x--[o|o] ", "     ___  ");
    Sprite sprite2 = Sprite();
    sprite2.setSprites("    (---) ", " +--[o|o] ", "     ___  ");
    sprites = SpriteAnimado(sprite1, sprite2);
    ativo = true;
}

Helicoptero::Helicoptero(int numX, int numY){
    Sprite sprite1 = Sprite();
    sprite1.setSprites("   (-----)", " x--[o|o] ", "     ___  ");
    Sprite sprite2 = Sprite();
    sprite2.setSprites("    (---) ", " +--[o|o] ", "     ___  ");
    sprites = SpriteAnimado(sprite1, sprite2);
    x = numX;
    y = numY;
    ativo = true;
}