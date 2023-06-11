#include <iostream>
#include <fstream>
#include <unistd.h>
#include "Fase.hpp"
#include "SpriteAnimado.hpp"
#include "Pessoa.hpp"
#include "GameBase.hpp"
#include "Obstaculo.hpp"
#include "Sprite.hpp"
#include "Base.hpp"
#include "Game.hpp"
#include "Helicoptero.hpp"
using namespace std;


int main() {
    //esse main está sendo usado para testes, por isso o código é sem objeto e não é intuitivo
    Game game = Game();
    game.rodar();
    return 0;
}
