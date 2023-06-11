#ifndef HELICOPTERO_HPP
#define HELICOPTERO_HPP
#include "ObjetoDoJogo.hpp"
#include <vector>

class Helicoptero: public ObjetoDoJogo{
private:
    int capacidadeMax;
    int qntPessoas;
    float combustivel;
    float combustivelMax;
    vector<ObjetoDoJogo> pessoasResgatadas;
public:
    Helicoptero();
    Helicoptero(string caminhoDoArquivo ,int numX, int numY);
    int getQntPessoas();
    int getCapacidadeMax();
    float getCombustivel();
    float getCombustivelMax();
    void atualizar() override;
    void operator+(ObjetoDoJogo pessoa);
    void abastece(int qnt);
    ObjetoDoJogo operator--();
    vector<ObjetoDoJogo> getPessoasResgatadas();
};


#endif