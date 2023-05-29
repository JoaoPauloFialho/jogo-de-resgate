#ifndef OBJETODOJOGO_H
#define OBJETODOJOGO_H
#include "SpriteAnimado.h"

class ObjetoDoJogo
{
protected:
    SpriteAnimado sprites;
    int x;
    int y;
    bool ativo;
public:
    ObjetoDoJogo();
    void colideComObjeto(ObjetoDoJogo obj){};
    void atualizaSprite();
    void moveTo();
    void ativa();
    void desativa();
    void desenharSla();
    int getX();
    int getY();
    SpriteAnimado getSprites();
};

#endif