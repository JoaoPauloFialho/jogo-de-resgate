#ifndef GAME_H
#define GAME_H
#include "ObjetoDoJogo.h"
#include "Base.h"
#include "Helicoptero.h"
#include <vector>
#include <iostream>
using namespace std;

class Game{
    private:
        vector<ObjetoDoJogo> objetos;
        Base base;
        Helicoptero helicoptero;
        string tela[30][50];
        int qntdPessoasResgatadas;
        bool executando;
    public:
        Game();
        Game(vector<ObjetoDoJogo> objetosDoJogo);
        void mostrar();
        void inicializar();
        void atualizar(string cmd);
        void desenharEntidade(ObjetoDoJogo obj);
        void jogar();
};

#endif