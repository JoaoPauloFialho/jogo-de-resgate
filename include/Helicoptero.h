#ifndef HELICOPTERO_H
#define HELICOPTERO_H
#include "ObjetoDoJogo.h"
#include <vector>

class Helicoptero: public ObjetoDoJogo{
private:
    int capacidade;
    vector<ObjetoDoJogo> pessoasResgatadas;
public:
    Helicoptero();
    Helicoptero(string caminhoDoArquivo ,int numX, int numY);
    void setCapacidade(int num);
    int getCapacidade();
    void operator+(ObjetoDoJogo pessoa);
    ObjetoDoJogo operator--();
    vector<ObjetoDoJogo> getPessoasResgatadas();
};


#endif