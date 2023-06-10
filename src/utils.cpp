#include "utils.h"
#include <iostream>
using namespace std;

namespace util{
    int calcularPorcentagem(float valor, float total) {
        if (total == 0) {
            return 0.0;
        }

        float porcentagem = (valor / total) * 100.0;
        return static_cast<int>(porcentagem);
    }

}
