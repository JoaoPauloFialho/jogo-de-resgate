#include <iostream>
#include <fstream>
#include <unistd.h>
#include "Fase.h"
#include "SpriteAnimado.h"
#include "Pessoa.h"
#include "GameBase.h"
#include "Obstaculo.h"
#include "Sprite.h"
#include "Base.h"
#include "Game.h"
#include "Helicoptero.h"
using namespace std;


int main() {
    //esse main está sendo usado para testes, por isso o código é sem objeto e não é intuitivo
    Game game = Game();
    game.rodar();
    return 0;
}
