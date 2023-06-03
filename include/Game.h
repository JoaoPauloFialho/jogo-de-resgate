#ifndef GAME_H
#define GAME_H
#include "ObjetoDoJogo.h"
#include <vector>
#include <iostream>
using namespace std;

class Game{
    private:
        vector<ObjetoDoJogo> objetos;
        string tela[30][50];
        bool executando;
    public:
        Game();
        Game(vector<ObjetoDoJogo> objetosDoJogo);
        void mostrar();
        void inicializar();
        void atualizar(string cmd);
        void desenhar(ObjetoDoJogo obj);
        void jogar();
};

#endif