#include "player.hpp"
#include <stdio.h>
#include <stdexcept>
#include <string>
#include <vector>
#include "card.hpp"

using namespace std;

namespace ariel{

    string name;

    // track cards won
    int cardsWon;
    std::vector<card> deck;
    
    // constructor
    Player::Player(string name) : name(name), cardsWon(0), deck() {
        std::vector<card> deck;
    }


    int Player::stacksize(){
        return this->deck.size();
    }

    int Player::cardesTaken(){
        return cardsWon;
    }

    // add cards accordingly (if there's a tie it will add more than 2)
    void Player::addCards(double num){
        this->cardsWon=cardsWon+2+4*num;
    }

}

