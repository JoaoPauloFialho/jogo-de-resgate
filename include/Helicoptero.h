#ifndef HELICOPTERO_H
#define HELICOPTERO_H
#include "ObjetoDoJogo.h"
#include <vector>

class Helicoptero: public ObjetoDoJogo{
private:
    int capacidadeMax;
    int qntPessoas;
    vector<ObjetoDoJogo> pessoasResgatadas;
public:
    Helicoptero();
    Helicoptero(string caminhoDoArquivo ,int numX, int numY);
    int getQntPessoas();
    int getCapacidadeMax();
    void operator+(ObjetoDoJogo pessoa);
    ObjetoDoJogo operator--();
    vector<ObjetoDoJogo> getPessoasResgatadas();
};


#endif