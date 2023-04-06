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
        
        card::card(int number,char suit):number(number),suit(suit){}
        int card::getNumber() 
        { return number;}
        char card::getSuit() 
         {return suit;}
        // int card::number;
        // char card::suit;

}