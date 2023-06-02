#ifndef OBJETODOJOGO_H
#define OBJETODOJOGO_H
#include "SpriteAnimado.h"

class ObjetoDoJogo
{
protected:
    SpriteAnimado sprites;
    int x;
    int y;
    int altura;
    int largura;
    bool ativo;
public:
    ObjetoDoJogo();
    ObjetoDoJogo(string caminhoDoArquivo, int numX, int numY);    
    void colideComObjeto(ObjetoDoJogo obj){};
    void atualizaSprite();
    void moveTo(string lado);
    void ativa();
    void desativa();
    bool getAtivo();
    void setX(int numero);
    void setY(int numero);
    int getX();
    int getAltura();
    int getLargura();
    int getY();
    SpriteAnimado getSprites();
};

#endif