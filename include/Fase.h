#ifndef FASE_H
#define FASE_H
#include "ObjetoDoJogo.h"
#include "Base.h"
#include "Sprite.h"
#include "Helicoptero.h"
#include "constantes.h"
#include "GameBase.h"
#include <vector>
#include <iostream>
using namespace std;

class Fase: public GameBase{
    private:
        vector<ObjetoDoJogo> objetos;
        Base base;
        Helicoptero helicoptero;
        SpriteAnimado background;
        string secaoInformacoes[jogo::ALTURASECAOINFORMACOES][jogo::LARGURAJOGO];
        string secaoJogo[jogo::ALTURAJOGO][jogo::LARGURAJOGO];
        int qntdPessoasResgatadas;
        bool executando;
    public:
        Fase();
        Fase(vector<ObjetoDoJogo> objetosDoJogo);
        void mostrar();
        void inicializar() override;
        void atualizar() override;
        void desenhar(ObjetoDoJogo obj);
        void desenhar(int y, int x, Sprite obj);
        void jogar();
};

#endif