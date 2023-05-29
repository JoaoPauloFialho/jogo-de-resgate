#include <iostream>
#include <fstream>
#include "Game.h"
#include "SpriteAnimado.h"
#include "Sprite.h"
#include "Helicoptero.h"


int main() {
    Game game = Game();
    game.inicializar();
    Helicoptero hel = Helicoptero();
    //hel.desenharSla();
    game.desenhar(hel, hel.getX(), hel.getY());
    return 0;
}
