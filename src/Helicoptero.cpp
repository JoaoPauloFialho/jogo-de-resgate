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

void Helicoptero::operator+(ObjetoDoJogo pessoa){
    pessoasResgatadas.push_back(pessoa);
}

ObjetoDoJogo Helicoptero::operator--(){
    ObjetoDoJogo pessoa = pessoasResgatadas[pessoasResgatadas.size()-1];
    pessoasResgatadas.pop_back();
    return pessoa;
}

void Helicoptero::setCapacidade(int num){
    capacidade = num;
}

int Helicoptero::getCapacidade(){
    return capacidade;
}

vector<ObjetoDoJogo> Helicoptero::getPessoasResgatadas(){
    return pessoasResgatadas;
}