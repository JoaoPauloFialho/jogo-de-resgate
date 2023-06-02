#ifndef SPRITE_H
#define SPRITE_H
#include <iostream>
#include <vector>
using namespace std;

class Sprite{
    private:
        vector<string> linhas; //linhas do vetor
    public:
        Sprite();
        Sprite(vector<string> linhasSalvar);
        vector<string> getLinhas();
        void setSprites(vector<string> linhasSalvar);
};

#endif