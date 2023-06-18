#include "utils.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

namespace util{
    int calcularPorcentagem(float valor, float total) {
        if (total == 0) {
            return 0.0;
        }

        float porcentagem = (valor / total) * 100.0;
        return static_cast<int>(porcentagem);
    }

    int achaItemEmVetor(vector<string> &vetor, string item){
        auto iterador = find(vetor.begin(), vetor.end(), item);

        if (iterador != vetor.end())
            return iterador - vetor.begin();
        return -1;
    }
}
