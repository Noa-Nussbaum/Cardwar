#pragma once
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>

using namespace std;

namespace ariel{

class card{

    private:
        char suit;
        int number;

    public:
        card(int number, char suit);
        card(const card& other);
        card& operator=(const card& other);
        card(card&& other) noexcept;
        card& operator=(card&& other) noexcept;
        ~card();
        int getNumber();
        string getSuit();

    };

}
