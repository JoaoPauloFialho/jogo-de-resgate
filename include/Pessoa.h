#ifndef PESSOA_H
#define PESSOA_H
#include "ObjetoDoJogo.h"

class Pessoa: public ObjetoDoJogo{
    private:
public:
    Pessoa();
    Pessoa(string caminhoDoArquivo ,int numX, int numY);
    Pessoa(string caminhoDoArquivo ,int numX);
};

#endif