#ifndef GAME_H
#define GAME_H
#include "ObjetoDoJogo.h"
#include <vector>
#include <iostream>
using namespace std;

class Game{
    private:
        vector<ObjetoDoJogo> objetos;
        string tela[10][100];
    public:
        Game();
        Game(vector<ObjetoDoJogo> objetosDoJogo);
        void mostrar();
        void inicializar();
        void atualizar(string cmd);
        void desenhar(ObjetoDoJogo obj,int x, int y);
};

#endif