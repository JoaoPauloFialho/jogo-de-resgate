#include "Helicoptero.h"
#include "ObjetoDoJogo.h"
#include "constantes.h"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;


Helicoptero::Helicoptero(){
}

Helicoptero::Helicoptero(string caminhoDoArquivo ,int numX, int numY)
:ObjetoDoJogo(caminhoDoArquivo, numX, numY){
    combustivel = jogo::COMBUSTIVELMAX;
    capacidadeMax = jogo::CAPACIDADEPESSOASHELICOPTERO;
    qntPessoas = 0;
    obstaculo = false;
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

void Helicoptero::atualizar(){
    sprites.atualizar();
    combustivel--;
}

int Helicoptero::getQntPessoas(){
    return qntPessoas;
}

int Helicoptero::getCapacidadeMax(){
    return capacidadeMax;
}

int Helicoptero::getCombustivel(){
    return combustivel;
}

vector<ObjetoDoJogo> Helicoptero::getPessoasResgatadas(){
    return pessoasResgatadas;
}