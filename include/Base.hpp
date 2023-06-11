#ifndef BASE_HPP
#define BASE_HPP
#include "ObjetoDoJogo.hpp"
#include <vector>

class Base: public ObjetoDoJogo
{
private:
    vector<ObjetoDoJogo> pessoasResgatadas;
public:
    Base();
    Base(string caminhoDoArquivo ,int numX, int numY);
    vector<ObjetoDoJogo> getPessoasResgatadas();
    void operator+(ObjetoDoJogo pessoa);
};


#endif