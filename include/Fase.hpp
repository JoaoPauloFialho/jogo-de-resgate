#ifndef FASE_HPP
#define FASE_HPP
#include "ObjetoDoJogo.hpp"
#include "Base.hpp"
#include "Sprite.hpp"
#include "Helicoptero.hpp"
#include "constantes.hpp"
#include "GameBase.hpp"
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
        int pessoas;
        bool executando;
    public:
        Fase();
        Fase(vector<ObjetoDoJogo> objetosDoJogo, string caminhoBackground);
        void mostrar();
        void inicializar() override;
        void atualizar() override;
        void desenhar(ObjetoDoJogo obj);
        void desenhar(int y, int x, Sprite obj);
        void jogar();
};

#endif