#ifndef GAME_H
#define GAME_H
using namespace std;
#include "ObjetoDoJogo.h"

class Game{
    public:
        Game();
        void inicializar();
        void desenhar(ObjetoDoJogo obj,int x, int y);
};

#endif