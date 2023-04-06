#pragma once
#include "game.hpp"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include "player.hpp"
#include "card.hpp"


using namespace std;
namespace ariel{

class card{

    private:
        char suit;
        int number;
    
    public:
        card(int number, char suit);
        int getNumber();
        char getSuit();
    };
}