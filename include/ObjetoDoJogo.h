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
    ObjetoDoJogo(int numX, int numY);    
    void colideComObjeto(ObjetoDoJogo obj){};
    void atualizaSprite();
    void moveTo(string lado);
    void ativa();
    void desativa();
    bool getAtivo();
    int getX();
    void setX(int numero);
    void setY(int numero);
    int getY();
    SpriteAnimado getSprites();
};

#endif