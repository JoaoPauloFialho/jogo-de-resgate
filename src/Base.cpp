#include "Base.hpp"
#include "ObjetoDoJogo.hpp"
#include "Pessoa.hpp"
#include "constantes.hpp"
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


vector<ObjetoDoJogo*> Base::getPessoasResgatadas(){
    return pessoasResgatadas;
}

void Base::operator+(Pessoa *pessoa){
    int yNovo = jogo::YINICIALBASE-pessoa->getAltura()+1, xNovo=0;
    pessoasResgatadas.push_back(pessoa);
    pessoa->resgatar();
    for(int i = 0; i < pessoasResgatadas.size(); i++){
        //o novo x deve ser o x anterior mais a largura do objeto pessoa
        ObjetoDoJogo* pessoa = pessoasResgatadas[i];
        if(i == 0){
            xNovo = jogo::XINICIALBASE;
        }else{
            xNovo += jogo::XINICIALBASE+pessoa->getLargura()+1;
        }
    };
    pessoa->moveTo(xNovo, yNovo);
    pessoa->ativa();
}