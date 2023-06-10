#ifndef CONSTANTES_H
#define CONSTANTES_H

namespace jogo{
    const int DESLOCAMENTO = 1;
    const int LARGURAJOGO = 150;
    const int LARGURATELA = 151;
    const int ALTURAJOGO = 30;
    const int ALTURATELA = 40;
    const int PESSOASNIVELFACIL = 2;
    const int PESSOASNIVELMEDIO = 4;
    const int PESSOASNIVELDIFICIL = 6;
    const int ALTURAHELICOPTERO = 3;
    const int ALTURABASE = 2;
    const int YINICIALHELICOPTERO = ALTURAJOGO-ALTURABASE-ALTURAHELICOPTERO+1;
    const int XINICIALHELICOPTERO = 0;
    const int YINICIALBASE = ALTURAJOGO-ALTURABASE;
    const int XINICIALBASE = 0;
}

#endif