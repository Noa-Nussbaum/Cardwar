#include "player.hpp"
#include <stdio.h>
#include <stdexcept>
#include <string>

using namespace std;

namespace ariel{

    string name;
    int cardsLeft;
    int cardsWon;

    Player::Player(string name)
    : name(name), cardsLeft(26), cardsWon(0) {
        this->name=name;
}


    int Player::stacksize(){
        return cardsLeft;
    }

    int Player::cardesTaken(){
        return cardsWon;
    }

}

