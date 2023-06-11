#ifndef OBJETODOJOGO_HPP
#define OBJETODOJOGO_HPP
#include "SpriteAnimado.hpp"
#include "GameBase.hpp"

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
    bool item;
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
    void setX(int numero);
    void setY(int numero);
    int getX();
    bool getAtivo();
    bool getObstaculo();
    bool getItem();
    int getAltura();
    int getLargura();
    int getY();
    SpriteAnimado getSprites();
};

#endif