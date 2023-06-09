#include "Game.h"
     
Game::Game(){};
     
void Game::inicializar(){
    for(int i=0; i < jogo::ALTURAJOGO; i++){
        for(int j=0; j < jogo::LARGURAJOGO; j++){
            tela[i][j] = ' ';
        }
    }
};  
    
void Game::atualizar(){};
    
void Game::rodar(){};