#ifndef OBSTACULO_HPP
#define OBSTACULO_HPP
#include "ObjetoDoJogo.hpp"

class Obstaculo: public ObjetoDoJogo{
    private:
public:
    Obstaculo();
    Obstaculo(string caminhoDoArquivo ,int numX, int numY);
    Obstaculo(string caminhoDoArquivo ,int numX);
};

#endif