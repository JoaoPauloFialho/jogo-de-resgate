#ifndef CONSTANTES_H
#define CONSTANTES_H

namespace jogo{
    const int LARGURAJOGO = 120;
    const int DESLOCAMENTO = 1;
    const int ALTURAJOGO = 30;
    const int PESSOASNIVELFACIL = 2;
    const int PESSOASNIVELMEDIO = 4;
    const int PESSOASNIVELDIFICIL = 6;
    const int ALTURAHELICOPTERO = 3;
    const int ALTURABASE = 2;
    const int YINICIALHELICOPTERO = ALTURAJOGO-ALTURABASE-ALTURAHELICOPTERO;
    const int YINICIALBASE = ALTURAJOGO-ALTURABASE;
}

#endif