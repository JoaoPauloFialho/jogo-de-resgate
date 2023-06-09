#ifndef GAME_H
#define GAME_H
#include "GameBase.h"
#include "constantes.h"
#include <iostream>
using namespace std;
  
class Game: public GameBase{
    private:
        string tela[jogo::ALTURAJOGO][jogo::LARGURAJOGO];
    public:
        Game();
        void atualizar() override;
        void inicializar() override;
        void rodar();
};

#endif