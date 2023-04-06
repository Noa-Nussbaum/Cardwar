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
                // initialize the deck
                deck = std::vector<card>();
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

                // assign each player their cards
                for (std::vector<card>::size_type i = 0; i < 26; i++) {
                        player1.deck.push_back(deck.back());
                        deck.pop_back();
                        player2.deck.push_back(deck.back());
                        deck.pop_back();
                }                
        }
        

        void Game::playTurn(){};
        void Game::printLastTurn(){}; 
        void Game::playAll(){};
        void Game::printWiner(){};
        void Game::printLog(){};
        void Game::printStats(){};


}