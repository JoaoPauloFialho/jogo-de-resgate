#ifndef OBJETODOJOGO_H
#define OBJETODOJOGO_H
#include "SpriteAnimado.h"
#include "GameBase.h"

class ObjetoDoJogo: public GameBase
{
protected:
    SpriteAnimado sprites;
    int x;
    int y;
    int altura;
    int largura;
    bool ativo;
    bool obstaculo;
public:
    ObjetoDoJogo();
    ObjetoDoJogo(string caminhoDoArquivo, int numX, int numY);
    ObjetoDoJogo(string caminhoDoArquivo, int numX);    
    bool colideComObjeto(ObjetoDoJogo obj);
    void atualizar() override;
    void inicializar() override;
    void moveTo(string lado);
    void ativa();
    void desativa();
    bool getAtivo();
    void setX(int numero);
    void setY(int numero);
    int getX();
    bool getObstaculo();
    int getAltura();
    int getLargura();
    int getY();
    SpriteAnimado getSprites();
};

#endif