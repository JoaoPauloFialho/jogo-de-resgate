#include "Item.h"
#include "ObjetoDoJogo.h"
#include <vector>
#include <iostream>
#include <fstream>
#include "constantes.h"
using namespace std;


Item::Item(){
}

Item::Item(string caminhoDoArquivo ,int numX)
:ObjetoDoJogo(caminhoDoArquivo, numX){
    obstaculo = false;
    ativo = true;
    item = true;
    bonus = jogo::BONUSITEM;
};

Item::Item(string caminhoDoArquivo ,int numX, int numY)
:ObjetoDoJogo(caminhoDoArquivo, numX, numY){
    obstaculo = false;
    ativo = true;
    item = true;
    bonus = jogo::BONUSITEM;
};

int Item::getBonus(){
    return bonus;
}
