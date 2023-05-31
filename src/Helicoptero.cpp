#include "Helicoptero.h"
#include <vector>


Helicoptero::Helicoptero(){
    vector<string> linhasSprite;
    linhasSprite.push_back("   (-----)");
    linhasSprite.push_back(" x--[o|o] ");
    linhasSprite.push_back("     ___  ");
    Sprite sprite1 = Sprite(linhasSprite);
    linhasSprite.clear();
    linhasSprite.push_back("    (---) ");
    linhasSprite.push_back(" +--[o|o] ");
    linhasSprite.push_back("     ___  ");
    Sprite sprite2 = Sprite(linhasSprite);
    vector<Sprite> spritesSalvar;
    spritesSalvar.push_back(sprite1);
    spritesSalvar.push_back(sprite2);
    sprites = SpriteAnimado(spritesSalvar);
    ativo = true;
}

Helicoptero::Helicoptero(int numX, int numY){
    vector<string> linhasSprite;
    linhasSprite.push_back("   (-----)");
    linhasSprite.push_back(" x--[o|o] ");
    linhasSprite.push_back("     ___  ");
    Sprite sprite1 = Sprite(linhasSprite);
    linhasSprite.clear();
    linhasSprite.push_back("    (---) ");
    linhasSprite.push_back(" +--[o|o] ");
    linhasSprite.push_back("     ___  ");
    Sprite sprite2 = Sprite(linhasSprite);
    vector<Sprite> spritesSalvar;
    spritesSalvar.push_back(sprite1);
    spritesSalvar.push_back(sprite2);
    sprites = SpriteAnimado(spritesSalvar);
    x = numX;
    y = numY;
    ativo = true;
}