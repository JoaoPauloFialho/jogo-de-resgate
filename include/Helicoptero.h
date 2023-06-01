#ifndef HELICOPTERO_H
#define HELICOPTERO_H
#include "ObjetoDoJogo.h"

class Helicoptero: public ObjetoDoJogo{
private:
public:
    Helicoptero();
    Helicoptero(string caminhoDoArquivo ,int numX, int numY);
};


#endif