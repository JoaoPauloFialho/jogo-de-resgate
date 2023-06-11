#include "Base.hpp"
#include "ObjetoDoJogo.hpp"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

Base::Base(){
}

Base::Base(string caminhoDoArquivo ,int numX, int numY)
:ObjetoDoJogo(caminhoDoArquivo, numX, numY){
    obstaculo = false;
    ativo = true;
    item = false;
};

vector<ObjetoDoJogo> Base::getPessoasResgatadas(){
    return pessoasResgatadas;
}

void Base::operator+(ObjetoDoJogo pessoa){
    pessoasResgatadas.push_back(pessoa);
}