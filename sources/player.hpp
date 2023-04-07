#pragma once
#include <stdio.h>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "card.hpp"

using namespace std;

namespace ariel{

class Player{
    public:
        
        string name;
        int cardsWon;
        Player(string name);
        int stacksize();
        int cardesTaken();
        void addCards(double num);
        std::string getString();
        std::vector<card> deck;
    };
}