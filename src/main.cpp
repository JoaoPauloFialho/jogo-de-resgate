#include <iostream>
#include <fstream>
#include <unistd.h>
#include "Game.h"
#include "SpriteAnimado.h"
#include "Pessoa.h"
#include "Sprite.h"
#include "Base.h"
#include "Helicoptero.h"
using namespace std;


int main() {
    //esse main está sendo usado para testes, por isso o código é sem objeto e não é intuitivo
    vector<ObjetoDoJogo> objetosDoJogo;
    Pessoa pes("sprites/pessoa.txt",30 , 27);
    Pessoa pes2("sprites/pessoa.txt",35 , 27);
    objetosDoJogo.push_back(pes);
    objetosDoJogo.push_back(pes2);
    Game game = Game(objetosDoJogo);
    game.jogar();
    return 0;
}
