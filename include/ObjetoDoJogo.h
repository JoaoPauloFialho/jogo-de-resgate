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
    bool movel;
public:
    ObjetoDoJogo();
    ObjetoDoJogo(string caminhoDoArquivo, int numX, int numY);    
    bool colideComObjeto(ObjetoDoJogo obj);
    void atualiza();
    void moveTo(string lado);
    void ativa();
    void desativa();
    bool getAtivo();
    void setX(int numero);
    void setY(int numero);
    int getX();
    bool getMovel();
    int getAltura();
    int getLargura();
    int getY();
    SpriteAnimado getSprites();
};

#endif