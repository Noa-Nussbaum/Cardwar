#pragma once
#include <stdio.h>
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

namespace ariel{

class Player{
    private:
        string name;

    public:
        Player(string name);
        Player(){}
        
        int stacksize();
        int cardesTaken();
        std::string getString();
    };
}