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
                drawNum = 0;
                finalWinner = "";                
        }
        

        void Game::playTurn(){
                // each player plays, we remove the cards, store them
                // we compare their results 
                if (player1.stacksize() == 0){
                        throw std::runtime_error("Error: Game over");
                        exit(0);
                }

                // Play the turns
                int p1num = player1.deck.back().getNumber();
                string p1suit = player1.deck.back().getSuit();
                player1.deck.pop_back();

                int p2num = player2.deck.back().getNumber();
                string p2suit = player2.deck.back().getSuit();
                player2.deck.pop_back();

                string winner = "";

                // tie/draw
                if (p1num == p2num){
                        drawNum++;
                        winner = "neither";
                        lastTurn = player1.name + " played " + std::to_string(p1num) + " of " + p1suit + " and " + player2.name + " played " + std::to_string(p2num) + " of " + p2suit + ". " + winner + " wins.";
                        log.push_back(lastTurn);

                        if(player1.stacksize()==0){
                                cout << "tie" << endl;
                                exit(0);
                        }
                        // playTurn();
                }


                // ace wins all but 2
                if(p1num == 1){
                        if (p2num == 2){
                                winner = player2.name;
                                player2.addCards();
                        }
                        else{
                                winner = player1.name;
                                player1.addCards();
                        }
                }
                if(p2num == 1){
                        if (p1num == 2){
                                winner = player1.name;
                                player1.addCards();
                        }
                        else{
                                winner = player2.name;
                                player2.addCards();
                        }
                }
                else if(p1num>p2num){
                        winner = player1.name;
                        player1.addCards();
                }
                else{
                        winner = player2.name;
                        player2.addCards();
                }

                lastTurn = player1.name + " played " + std::to_string(p1num) + " of " + p1suit + " and " + player2.name + " played " + std::to_string(p2num) + " of " + p2suit + ". " + winner + " wins.";

                log.push_back(lastTurn);

                if(player1.stacksize()==0){
                        finalWinner = winner;
                }
                

        };

        void Game::printLastTurn(){
                if(player1.stacksize()==26){
                        throw std::runtime_error("Error: Game hasn't begun");
                        exit(0);
                }
                cout << lastTurn << endl;
        }; 

        void Game::playAll(){
                if(player1.stacksize()==0){
                        throw std::runtime_error("Error: Game over");
                        exit(0);
                }
                while(player1.stacksize()!=0){
                        playTurn();
                }
        };

        void Game::printWiner(){
                if(player1.stacksize()!=0){
                        throw std::runtime_error("Error: Game not over yet");
                        exit(0);
                }
                cout << this-> finalWinner << endl;
        };

        void Game::printLog(){
                if(player1.stacksize()==26){
                        throw std::runtime_error("Error: Game hasn't begun");
                        exit(0);
                }
                for (vector<string>::size_type i=0; i<log.size();i++){
                        cout << log[i] << endl;
                }
        };
        void Game::printStats(){
                cout << player1.name + " won " + std::to_string(player1.cardesTaken()) + " cards" << endl;
                cout << player2.name + " won " + std::to_string(player2.cardesTaken()) + " cards" << endl;
                string currWinner = "";
                if(player1.cardesTaken()>player2.cardesTaken()){
                        currWinner = player1.name;
                }
                if(player1.cardesTaken()<player2.cardesTaken()){
                        currWinner = player2.name;
                }
                else{
                        currWinner = "Neither";
                }
                cout << currWinner + " is winning" << endl;
                cout << "Number of draws: " + std::to_string(drawNum) << endl;



        };


}