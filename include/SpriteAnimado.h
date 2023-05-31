#ifndef SPRITEANIMADO_H
#define SPRITEANIMADO_H
#include <iostream>
#include "Sprite.h"
#include <vector>

class SpriteAnimado{
    private:
        vector<Sprite> sprites;
        int spriteAtual;
    public:
        SpriteAnimado();
        SpriteAnimado(vector<Sprite> spritesSalvar);
        void setSprites(vector<Sprite> spritesSalvar);
        vector<Sprite> getSprites();
        int getSpriteAtual();
        void trocarSpriteAtual();
};

#endif