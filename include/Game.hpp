#ifndef GAME_HPP
#define GAME_HPP
#include "GameBase.hpp"
#include "constantes.hpp"
#include <iostream>
using namespace std;
  
class Game: public GameBase{
    private:
    public:
        Game();
        void atualizar() override;
        void inicializar() override;
        void rodar();
};

#endif