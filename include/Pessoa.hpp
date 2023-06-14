#ifndef PESSOA_HPP
#define PESSOA_HPP
#include "ObjetoDoJogo.hpp"

class Pessoa: public ObjetoDoJogo{
    private:
        bool resgatada;
    public:
        Pessoa();
        Pessoa(string caminhoDoArquivo ,int numX, int numY);
        Pessoa(string caminhoDoArquivo ,int numX);
        void resgatar();
        bool getResgatada();
};

#endif