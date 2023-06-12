#ifndef GAME_HPP
#define GAME_HPP
#include "GameBase.hpp"
#include "constantes.hpp"
#include <iostream>
using namespace std;
  
class Game: public GameBase{
    private:
        static int faseAtual;
    public:
        Game();
        void atualizar() override;
        void inicializar() override;
        void rodar();
        int getFaseAtual();
};

#endif