#include "Sprite.h"
#include "SpriteMensagemPause.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

SpriteMensagemPause::SpriteMensagemPause(string caminhoDoArquivo){
    ifstream arquivo(caminhoDoArquivo);

    if (arquivo.is_open()) {
        string linha;
        cout << linha << endl;
        while (getline(arquivo, linha)) {
            linhas.push_back(linha);
        }
        arquivo.close();
    } else {
        //lembrar de adicionar uma exceção aqui no futuro
    }
}