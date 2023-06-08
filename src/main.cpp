#include <iostream>
#include <fstream>
#include <unistd.h>
#include "Fase.h"
#include "SpriteAnimado.h"
#include "Pessoa.h"
#include "Obstaculo.h"
#include "Sprite.h"
#include "Base.h"
#include "Helicoptero.h"
using namespace std;


int main() {
    //esse main está sendo usado para testes, por isso o código é sem objeto e não é intuitivo
    vector<ObjetoDoJogo> objetosDoJogo;
    Obstaculo obs("sprites/predio1.txt",40 , 18);
    Pessoa pes1("sprites/pessoa.txt",20 , 27);
    Pessoa pes2("sprites/pessoa.txt",80 , 27);
    objetosDoJogo.push_back(obs);
    objetosDoJogo.push_back(pes1);
    objetosDoJogo.push_back(pes2);
    Fase fase = Fase(objetosDoJogo);
    fase.jogar();
    return 0;
}
