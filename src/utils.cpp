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
        auto ret = find(vetor.begin(), vetor.end(), item);

        if (ret != vetor.end())
            return ret - vetor.begin();
        return -1;
}
}
