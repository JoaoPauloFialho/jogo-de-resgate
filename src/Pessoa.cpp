#include "Pessoa.h"
#include "ObjetoDoJogo.h"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;


Pessoa::Pessoa(){
}

Pessoa::Pessoa(string caminhoDoArquivo ,int numX, int numY)
:ObjetoDoJogo(caminhoDoArquivo, numX, numY){
    obstaculo = false;
    item = false;
    ativo = true;
};

Pessoa::Pessoa(string caminhoDoArquivo ,int numX)
:ObjetoDoJogo(caminhoDoArquivo, numX){
    obstaculo = false;
    item = false;
    ativo = true;
};