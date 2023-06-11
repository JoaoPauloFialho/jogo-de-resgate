#ifndef CONSTANTES_HPP
#define CONSTANTES_HPP

namespace jogo{
    const int DESLOCAMENTO = 1;
    const int LARGURAJOGO = 150;
    const int ALTURASECAOINFORMACOES = 3;
    const int ALTURAJOGO = 30;
    const int PESSOASRESGATAR = 6;
    const int BONUSITEM = 100;
    const int ALTURAHELICOPTERO = 3;
    const double COMBUSTIVELMAX = 500.0;
    const int CAPACIDADEPESSOASHELICOPTERO = 4;
    const int ALTURABASE = 2;
    const int YINICIALHELICOPTERO = ALTURAJOGO-ALTURABASE-ALTURAHELICOPTERO+1;
    const int XINICIALHELICOPTERO = 0;
    const int YINICIALBASE = ALTURAJOGO-ALTURABASE;
    const int XINICIALBASE = 0;
}

#endif