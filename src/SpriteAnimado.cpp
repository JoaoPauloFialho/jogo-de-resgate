#include <iostream>
#include <fstream>
#include <unistd.h>
#include <vector>
#include "SpriteAnimado.h"
#include "Sprite.h"
using namespace std;

SpriteAnimado::SpriteAnimado(){
    spriteAtual = 0;
};

SpriteAnimado::SpriteAnimado(vector<Sprite> spritesSalvar){
    spriteAtual = 0;
    for(int i = 0; i < spritesSalvar.size(); i ++){
        sprites.push_back(spritesSalvar[i]);
    }
}

SpriteAnimado::SpriteAnimado(string caminhoDoArquivo){
    spriteAtual = 0;
    try{
        ifstream arquivo(caminhoDoArquivo);
        if (!arquivo.is_open()) {
            throw exception();
        }else{
            int larguraSprite = 0;
            int alturaSprite = 0;
            vector<Sprite> spritesSalvar;
            vector<string> linhas;
            string linha;
            while (getline(arquivo, linha)) {
                if(linha == "proxsprite" || linha == "fimsprite"){
                    Sprite spriteSalvar = Sprite(linhas);
                    linhas.clear();
                    spritesSalvar.push_back(spriteSalvar);
                }else{
                    larguraSprite = linha.length()-1;
                    linhas.push_back(linha);
                };
            }
            sprites = spritesSalvar;
            largura = larguraSprite;
            altura = sprites[sprites.size()-1].getLinhas().size()-1;
            arquivo.close();
        };
    }catch(const exception& e){
        cerr << e.what();
    };
}

void SpriteAnimado::setSprites(vector<Sprite> spritesSalvar){
    spriteAtual = 0;
    for(int i = 0; i < spritesSalvar.size(); i ++){
        sprites.push_back(spritesSalvar[i]);
    }
};

void SpriteAnimado::atualizar(){
    if(spriteAtual == sprites.size()-1){
        spriteAtual = 0;
    }
    else{
        spriteAtual++;
    }
}

void SpriteAnimado::inicializar(){};

Sprite SpriteAnimado::getSpriteAtual(){
    return sprites[spriteAtual];
}

int SpriteAnimado::getAltura(){
    return altura;
}

int SpriteAnimado::getLargura(){
    return largura;
}

vector<Sprite> SpriteAnimado::getSprites(){
    return sprites;
}
