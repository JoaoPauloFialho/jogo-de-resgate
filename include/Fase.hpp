#ifndef FASE_HPP
#define FASE_HPP
#include "ObjetoDoJogo.hpp"
#include "Sound.hpp"
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
        vector<ObjetoDoJogo*> objetos;
        Base base;
        Helicoptero helicoptero;
        SpriteAnimado background;
        SpriteAnimado mensagem;
        string secaoInformacoes[jogo::ALTURASECAOINFORMACOES][jogo::LARGURAJOGO];
        string secaoJogo[jogo::ALTURAJOGO][jogo::LARGURAJOGO];
        Sound musica;
        int pessoas;
        bool vitoria;
    public:
        Fase();
        Fase(vector<ObjetoDoJogo*> objetosDoJogo, string caminhoBackground, string caminhoMensagem, string caminhoMusica);
        void mostrar();
        void inicializar() override;
        void atualizar() override;
        void desenhar(ObjetoDoJogo obj);
        void desenhar(int y, int x, SpriteAnimado obj);
        bool jogar();
};

#endif