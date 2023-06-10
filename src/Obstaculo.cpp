#include "Obstaculo.h"
#include "ObjetoDoJogo.h"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

Obstaculo::Obstaculo(){
}

Obstaculo::Obstaculo(string caminhoDoArquivo ,int numX, int numY)
:ObjetoDoJogo(caminhoDoArquivo, numX, numY){
    obstaculo = true;
    ativo = true;
    item = false;
};

Obstaculo::Obstaculo(string caminhoDoArquivo ,int numX)
:ObjetoDoJogo(caminhoDoArquivo, numX){
    obstaculo = true;
    ativo = true;
    item = false;
};