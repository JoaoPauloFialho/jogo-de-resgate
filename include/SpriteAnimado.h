#ifndef SPRITEANIMADO_H
#define SPRITEANIMADO_H
#include <iostream>
#include "Sprite.h"

class SpriteAnimado{
    private:
        Sprite sprites[2];
        int spriteAtual;
    public:
        SpriteAnimado(Sprite sprite1, Sprite sprite2);
        SpriteAnimado();
        void desenharNaTela(int x, int y);
        void setSprites(Sprite lista[2]);
        Sprite* getSprites();
        int getSpriteAtual();
        void trocarSpriteAtual();
};

#endif