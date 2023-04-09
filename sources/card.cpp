#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include "card.hpp"

using namespace std;
namespace ariel{
        
        // copy constructor
        card::card(const card& copy){
                this->number=copy.number;
                this->suit=copy.suit;
        }
        
        // constructor
        card::card(int number, char suit):number(number),suit(suit){}

        // returns number
        int card::getNumber() 
        { return number;}

        // returns suit
        string card::getSuit() {
                if(this->suit == 'H'){
                        return "Hearts";
                }
                if(this->suit == 'S'){
                        return "Spades";
                }
                if(this->suit == 'D'){
                        return "Diamonds";
                }
                return "Clubs";

        }
    // copy assignment operator
    card& card::operator=(const card& other){
    if(this != &other){
        this->number = other.number;
        this->suit = other.suit;
    }
    return *this;
    }

    // move constructor
    card::card(card&& other) noexcept{
        this->number = other.number;
        this->suit = other.suit;
        other.number = 0;
        other.suit = '\0';
    }

    // move assignment operator
    card& card::operator=(card&& other) noexcept{
        if(this != &other){
            this->number = other.number;
            this->suit = other.suit;
            other.number = 0;
            other.suit = '\0';
        }
        return *this;
    }


    // destructor
    card::~card() {}


}