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
#include "Helicoptero.h"
using namespace std;


int main() {
    //esse main está sendo usado para testes, por isso o código é sem objeto e não é intuitivo
    vector<ObjetoDoJogo> objetosDoJogo;
    Obstaculo obs("sprites/predio1.txt",40);
    Obstaculo carro("sprites/carro1.txt", 79);
    Obstaculo fogo1("sprites/fogo.txt", 82, jogo::ALTURAJOGO-carro.getAltura()-2);
    Obstaculo fogo2("sprites/fogo.txt", 87);
    Pessoa pes1("sprites/pessoa.txt",42, 15);
    Pessoa pes2("sprites/pessoa.txt",95);
    Pessoa pes3("sprites/pessoa.txt",99);
    Obstaculo onibus("sprites/onibus1.txt", 105);
    Obstaculo fogo3("sprites/fogo.txt", 107, jogo::ALTURAJOGO-onibus.getAltura()-2);
    Obstaculo fogo4("sprites/fogo.txt", 115, jogo::ALTURAJOGO-onibus.getAltura());
    Obstaculo fogo5("sprites/fogo.txt", 120, jogo::ALTURAJOGO-onibus.getAltura()-3);
    Obstaculo fogo6("sprites/fogo.txt", 124);
    objetosDoJogo.push_back(obs);
    objetosDoJogo.push_back(carro);
    objetosDoJogo.push_back(fogo1);
    objetosDoJogo.push_back(fogo2);
    objetosDoJogo.push_back(pes1);
    objetosDoJogo.push_back(pes2);
    objetosDoJogo.push_back(pes3);
    objetosDoJogo.push_back(onibus);
    objetosDoJogo.push_back(fogo3);
    objetosDoJogo.push_back(fogo4);
    objetosDoJogo.push_back(fogo5);
    objetosDoJogo.push_back(fogo6);
    Fase fase = Fase(objetosDoJogo);
    fase.jogar();
    return 0;
}
