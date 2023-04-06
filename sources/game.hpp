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
        string finalWinner;
        void printWiner();

        std::vector<string> log;
        void printLog();

        int drawNum;
        int currDrawNum;
        void printStats();

    };

}