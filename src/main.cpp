#include <iostream>
#include <fstream>
#include <unistd.h>
#include "Game.h"
#include "SpriteAnimado.h"
#include "Sprite.h"
#include "Helicoptero.h"
using namespace std;


int main() {
    vector<ObjetoDoJogo> objetosDoJogo;
    Helicoptero hel = Helicoptero(3, 3);
    objetosDoJogo.push_back(hel);
    Game game = Game(objetosDoJogo);
    string andar;
    game.inicializar();
    while(1){
        game.mostrar();
        cin >> andar;
        game.atualizar(andar);
        system("clear");
    }
    return 0;
}
