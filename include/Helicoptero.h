#ifndef HELICOPTERO_H
#define HELICOPTERO_H
#include "ObjetoDoJogo.h"
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