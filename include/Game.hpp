#ifndef GAME_HPP
#define GAME_HPP
#include "GameBase.hpp"
#include "constantes.hpp"
#include "SpriteAnimado.hpp"
#include <iostream>
#include <vector>
using namespace std;
  
class Game: public GameBase{
    private:
        int faseAtual;
        string tela[jogo::ALTURATELA][jogo::LARGURATELA];
        vector<string> opcoes;
        int opcaoAtual;
        SpriteAnimado nomeJogo;
    public:
        Game();
        void atualizar() override;
        void inicializar() override;
        void desenhar(int y, int x,SpriteAnimado spr);
        void rodar();
        void mostrar();
        int getFaseAtual();
};

#endif