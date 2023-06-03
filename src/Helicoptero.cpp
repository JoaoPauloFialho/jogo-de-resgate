#include "Helicoptero.h"
#include "ObjetoDoJogo.h"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;


Helicoptero::Helicoptero(){
}

Helicoptero::Helicoptero(string caminhoDoArquivo ,int numX, int numY)
:ObjetoDoJogo(caminhoDoArquivo, numX, numY){
    movel = true;
};

void Helicoptero::setCapacidade(int num){
    capacidade = num;
}

int Helicoptero::getCapacidade(){
    return capacidade;
}