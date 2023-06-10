#ifndef ITEM_H
#define ITEM_H
#include "ObjetoDoJogo.h"

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