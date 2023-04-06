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
        
        card::card(const card& copy){
                this->number=copy.number;
                this->suit=copy.suit;
        }
        
        card::card(int number, char suit):number(number),suit(suit){}

        int card::getNumber() 
        { return number;}
        char card::getSuit() 
         {return suit;}
        // int card::number;
        // char card::suit;

}