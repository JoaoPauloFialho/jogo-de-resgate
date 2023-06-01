#include <iostream>
#include <fstream>
#include <unistd.h>
#include "Game.h"
#include "SpriteAnimado.h"
#include "Sprite.h"
#include "Helicoptero.h"
using namespace std;


int main() {
    //esse main está sendo usado para testes, por isso o código é sem objeto e não é intuitivo
    vector<ObjetoDoJogo> objetosDoJogo;
    Helicoptero hel = Helicoptero(3 , 3);
    objetosDoJogo.push_back(hel);
    Game game = Game(objetosDoJogo);
    string andar;
    string chico = "abc";
    chico += "def";
    cout << chico;
    game.inicializar();
    while(1){
        game.mostrar();
        cin >> andar;
        game.atualizar(andar);
        system("clear");
    }
    return 0;
}
