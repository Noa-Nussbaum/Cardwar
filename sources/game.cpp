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

        Game::Game(Player p1, Player p2) : player1(p1), player2(p2) {
                // player1.cardsLeft=26;
                // player2.cardsLeft=26;
        }

        void Game::playTurn(){};
        void Game::printLastTurn(){}; 
        void Game::playAll(){};
        void Game::printWiner(){};
        void Game::printLog(){};
        void Game::printStats(){};


}