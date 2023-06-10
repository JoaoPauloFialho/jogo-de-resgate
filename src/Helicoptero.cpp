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
    combustivelMax = jogo::COMBUSTIVELMAX;
    capacidadeMax = jogo::CAPACIDADEPESSOASHELICOPTERO;
    qntPessoas = 0;
    obstaculo = false;
    ativo = true;
    item = false;
};

void Helicoptero::operator+(ObjetoDoJogo pessoa){
    pessoasResgatadas.push_back(pessoa);
    qntPessoas++;
}

void Helicoptero::abastece(int qnt){
    if(combustivel + qnt > combustivelMax){
        combustivel = combustivelMax;
    }else{
        combustivel += qnt;
    }
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

float Helicoptero::getCombustivel(){
    return combustivel;
}

float Helicoptero::getCombustivelMax(){
    return combustivelMax;
}

vector<ObjetoDoJogo> Helicoptero::getPessoasResgatadas(){
    return pessoasResgatadas;
}