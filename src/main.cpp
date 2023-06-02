#include <iostream>
#include <fstream>
#include <unistd.h>
#include "Game.h"
#include "SpriteAnimado.h"
#include "Pessoa.h"
#include "Sprite.h"
#include "Helicoptero.h"
using namespace std;


int main() {
    //esse main está sendo usado para testes, por isso o código é sem objeto e não é intuitivo
    vector<ObjetoDoJogo> objetosDoJogo;
    Helicoptero hel("sprites/helicoptero.txt",0 , 0);
    Pessoa pes("sprites/pessoa.txt",10 , 30);
    objetosDoJogo.push_back(hel);
    objetosDoJogo.push_back(pes);
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
