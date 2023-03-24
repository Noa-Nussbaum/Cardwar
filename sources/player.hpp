#ifndef PLAYER_HP
#define PLAYER_H
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>

using namespace std;

namespace ariel{

class Player{
    public:
        Player(string name);
        void stacksize();
        void cardesTaken();
    private:
        int stacksize;
        int cardesTaken;
        string name;
    };
}

#endif