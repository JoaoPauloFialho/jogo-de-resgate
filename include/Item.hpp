#ifndef ITEM_HPP
#define ITEM_HPP
#include "ObjetoDoJogo.hpp"

class Item:public ObjetoDoJogo{
    private:
        int bonus;
    public:
        Item();
        Item(string caminhoDoArquivo ,int numX, int numY);
        Item(string caminhoDoArquivo ,int numX);
        int getBonus();
};

#endif