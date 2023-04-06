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
    private:
        
        string name;
        int cardsWon;
    
    public:
        Player(string name);
        int stacksize();
        int cardesTaken();
        std::string getString();
        std::vector<card> deck;
    };
}