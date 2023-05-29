#include "Game.h"
#include <iostream>
#include <fstream>
using namespace std;

Game::Game(){};

void Game::inicializar(){
    std::ofstream arquivo("jogo.txt");

    if (arquivo.is_open()) {
        for(int i = 0; i < 40; i++){
            if(i == 0 || i == 39){
                for(int j = 1; j < 160; j++){
                    arquivo << ' ';
                    if(j == 159) arquivo << '\n';
                }
            }
            else{
                for(int j = 1; j < 160; j++){
                    if(j == 1){
                         arquivo << " ";
                    }else if(j == 159){
                        arquivo << " \n";
                    } else{
                        arquivo << ' ';
                    }
                }
            }
        }
    } else {
        std::cout << "Erro ao abrir o arquivo." << std::endl;
    }
    arquivo.close();
};

void Game::desenhar(ObjetoDoJogo obj, int x, int y){
    int spriteAtual = obj.getSprites().getSpriteAtual();
    SpriteAnimado sprites = obj.getSprites();

    string linha1 = sprites.getSprites()[spriteAtual].getSprite()[0];
    string linha2 = sprites.getSprites()[spriteAtual].getSprite()[1];
    string linha3 = sprites.getSprites()[spriteAtual].getSprite()[2];
    cout << linha1 << endl;
    cout << linha2 << endl;
    cout << linha3 << endl;
}