#ifndef SPRITEANIMADO_H
#define SPRITEANIMADO_H
#include <iostream>
#include "Sprite.h"
#include "GameBase.h"
#include <vector>

class SpriteAnimado: public GameBase{
    private:
        vector<Sprite> sprites;
        int spriteAtual;
        int altura;
        int largura;
    public:
        SpriteAnimado();
        SpriteAnimado(vector<Sprite> spritesSalvar);
        SpriteAnimado(string caminhoDoArquivo);
        void setSprites(vector<Sprite> spritesSalvar);
        vector<Sprite> getSprites();
        int getAltura();
        int getLargura();
        Sprite getSpriteAtual();
        void atualizar() override;
        void inicializar() override;
};

#endif