#ifndef SPRITEANIMADO_HPP
#define SPRITEANIMADO_HPP
#include <iostream>
#include "Sprite.hpp"
#include "GameBase.hpp"
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