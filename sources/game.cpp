#include "game.hpp"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include "player.hpp"
#include "card.hpp"
#include <vector>
#include <random>
#include <algorithm>

using namespace std;
namespace ariel{

        Game::Game(Player &p1, Player &p2) : player1(p1), player2(p2) {
               // create a deck of cards
                std::vector<card> deck;
                player1.cardsLeft=26;
                player2.cardsLeft=26;
                
                for (int number = 1; number <= 13; ++number) {
                        deck.emplace_back(number, 'H');
                        deck.emplace_back(number, 'D');
                        deck.emplace_back(number, 'C');
                        deck.emplace_back(number, 'S');
                }

                // shuffle the deck
                std::random_device rd;
                std::mt19937 g(rd());
                std::shuffle(deck.begin(), deck.end(), g);  
                this->deck=deck;   
                cout << "deck size:" << deck.size() << endl;   

        }

        void Game::playTurn(){};
        void Game::printLastTurn(){}; 
        void Game::playAll(){};
        void Game::printWiner(){};
        void Game::printLog(){};
        void Game::printStats(){};


}