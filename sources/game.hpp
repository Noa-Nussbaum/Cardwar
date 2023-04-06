#pragma once
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include "player.hpp"
#include <vector>
#include "card.hpp"

using namespace std;

namespace ariel{

class Game{
     private:
        Player player1;
        Player player2;
        std::vector<card> deck;
    public:
        Game(Player& player1, Player& player2);
        void playTurn();
        void printLastTurn(); 
        void playAll();
        void printWiner();
        void printLog();
        void printStats();
   
    
    };

}