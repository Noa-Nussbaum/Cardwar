#pragma once
#include <stdio.h>
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

namespace ariel{

class Player{
    
    public:
        Player(string name);
        int stacksize();
        int cardesTaken();
        std::string getString();
        string name;
        int cardsLeft;
        int cardsWon;
    };
}