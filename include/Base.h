#ifndef BASE_H
#define BASE_H
#include "ObjetoDoJogo.h"
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