#include "player.hpp"
#include <stdio.h>
#include <stdexcept>
#include <string>
#include <vector>
#include "card.hpp"

using namespace std;

namespace ariel{

    string name;
    int cardsWon;
    std::vector<card> deck;
    
    Player::Player(string name) : name(name), cardsWon(0), deck() {
        std::vector<card> deck;
    }


    int Player::stacksize(){
        return this->deck.size();
    }

    int Player::cardesTaken(){
        return cardsWon;
    }

    void Player::addCards(){
        this->cardsWon=cardsWon+2;
    }

}

