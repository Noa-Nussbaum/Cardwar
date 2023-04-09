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

     public:
        Player& player1;
        Player& player2;

        std::vector<card> deck;

        Game(Player &player1, Player &player2);

        void playTurn();

        string lastTurn;
        void printLastTurn(); 

        void playAll();
        
        void printWiner();

        std::vector<string> log;
        void printLog();

        // keep track of draws for final stats
        int drawNum;

        // keep track of current draws to add cards accordingly
        int currDrawNum;

        void printStats();

        // flag if there's only one player
        int onePlayer;


    };

}