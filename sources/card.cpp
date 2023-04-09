#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
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


        // Destructor
        card::~card() {}


}