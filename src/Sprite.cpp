#include <iostream>
#include "Sprite.hpp"
#include <vector>
using namespace std;

Sprite::Sprite(){}

Sprite::Sprite(vector<string> linhasSalvar){
    for(int i = 0; i < linhasSalvar.size(); i++){
        linhas.push_back(linhasSalvar[i]);
    }
}
vector<string> Sprite::getLinhas(){ 
    return linhas;
    };
    
void Sprite::setSprites(vector<string> linhasSalvar){
    linhas.clear();
    for(int i = 0; i < linhasSalvar.size(); i++){
        linhas.push_back(linhasSalvar[i]);
    }
};