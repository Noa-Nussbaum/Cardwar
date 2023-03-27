#include "game.hpp"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include "player.hpp"

using namespace std;
namespace ariel{


    
        Game::Game(Player player1, Player player2){};
        void Game::playTurn(){};
        void Game::printLastTurn(){}; 
        void Game::playAll(){};
        void Game::printWiner(){};
        void Game::printLog(){};
        void Game::printStats(){};
    
        Player player1;
        Player player2;
        string lastTurn;
        string Log; //All turns concatenated

    

}