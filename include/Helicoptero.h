#ifndef HELICOPTERO_H
#define HELICOPTERO_H
#include "ObjetoDoJogo.h"

class Helicoptero: public ObjetoDoJogo{
private:
    int capacidade;
public:
    Helicoptero();
    Helicoptero(string caminhoDoArquivo ,int numX, int numY);
    void setCapacidade(int num);
    int getCapacidade();
};


#endif