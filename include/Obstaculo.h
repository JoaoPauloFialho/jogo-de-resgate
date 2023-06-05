#ifndef OBSTACULO_H
#define OBSTACULO_H
#include "ObjetoDoJogo.h"

class Obstaculo: public ObjetoDoJogo{
    private:
public:
    Obstaculo();
    Obstaculo(string caminhoDoArquivo ,int numX, int numY);
};

#endif