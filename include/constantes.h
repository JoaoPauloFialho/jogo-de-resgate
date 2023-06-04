#ifndef CONSTANTES_H
#define CONSTANTES_H

namespace jogo{
    const int LARGURAJOGO = 50;
    const int ALTURAJOGO = 30;
    const int PESSOASNIVELFACIL = 2;
    const int ALTURAHELICOPTERO = 3;
    const int ALTURABASE = 2;
    const int YINICIALHELICOPTERO = ALTURAJOGO-ALTURABASE-ALTURAHELICOPTERO;
    const int YINICIALBASE = ALTURAJOGO-ALTURABASE;
}

#endif