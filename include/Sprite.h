#ifndef SPRITE_H
#define SPRITE_H
#include <iostream>
using namespace std;

class Sprite{
    private:
        string sprite[3];
    public:
        Sprite();
        string* getSprite();
        void setSprites(string linha1, string linha2, string linha3);
};

#endif