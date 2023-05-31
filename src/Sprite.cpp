#include <iostream>
#include "Sprite.h"
#include <vector>
using namespace std;

Sprite::Sprite(){}

Sprite::Sprite(vector<string> linhasSalvar){
    for(int i = 0; i < linhasSalvar.size(); i++){
        linhas.push_back(linhasSalvar[i]);
    }
}
vector<string> Sprite::getSprite(){ 
    return linhas;
    };
    
void Sprite::setSprites(vector<string> linhasSalvar){
    linhas.clear();
    for(int i = 0; i < linhasSalvar.size(); i++){
        linhas.push_back(linhasSalvar[i]);
    }
};