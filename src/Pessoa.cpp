#include "Pessoa.hpp"
#include "ObjetoDoJogo.hpp"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;


Pessoa::Pessoa(){
}

Pessoa::Pessoa(string caminhoDoArquivo ,int numX, int numY)
:ObjetoDoJogo(caminhoDoArquivo, numX, numY){
    obstaculo = false;
    resgatada = false;
    item = false;
    ativo = true;
};

Pessoa::Pessoa(string caminhoDoArquivo ,int numX)
:ObjetoDoJogo(caminhoDoArquivo, numX){
    obstaculo = false;
    resgatada = false;
    item = false;
    ativo = true;
};

void Pessoa::resgatar(){
    resgatada = true;
}

bool Pessoa::getResgatada(){
    return resgatada;
}