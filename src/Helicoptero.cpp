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
    capacidadeMax = 2;
    qntPessoas = 0;
    movel = true;
};

void Helicoptero::operator+(ObjetoDoJogo pessoa){
    pessoasResgatadas.push_back(pessoa);
    qntPessoas++;
}

ObjetoDoJogo Helicoptero::operator--(){
    ObjetoDoJogo pessoa = pessoasResgatadas[pessoasResgatadas.size()-1];
    pessoasResgatadas.pop_back();
    qntPessoas--;
    return pessoa;
}

int Helicoptero::getQntPessoas(){
    return qntPessoas;
}

int Helicoptero::getCapacidadeMax(){
    return capacidadeMax;
}

vector<ObjetoDoJogo> Helicoptero::getPessoasResgatadas(){
    return pessoasResgatadas;
}