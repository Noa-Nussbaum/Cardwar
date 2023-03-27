#include "doctest.h"
#include "sources/card.hpp"
#include "sources/game.hpp"
#include "sources/player.hpp"
#include <stdexcept>

using namespace std;

namespace ariel{

TEST_CASE("Player initialization"){
    Player player1("Noa");
    Player player2("Hodaya");
    Game game(player1,player2);

    CHECK(player1.stacksize()==26);
    CHECK(player1.cardesTaken()==0);

    CHECK(player2.stacksize()==26);
    CHECK(player2.cardesTaken()==0);
}

TEST_CASE("Game initialization"){
    Player player1("Noa");
    Player player2("Hodaya");
    Game Game(player1,player2);

    REQUIRE_NOTHROW(Game.playTurn());
    REQUIRE_NOTHROW(Game.printLastTurn());
    REQUIRE_NOTHROW(Game.playAll());
    REQUIRE_NOTHROW(Game.printWiner());
    REQUIRE_NOTHROW(Game.printLog());
    REQUIRE_NOTHROW(Game.printStats());
    
}

TEST_CASE("Game has started"){
    Player player1("Noa");
    Player player2("Hodaya");
    Game Game(player1,player2);
    Game.playTurn();
    CHECK(player1.stacksize()==25);
    CHECK(player2.stacksize()==25);
    
}

TEST_CASE("Entire game"){
    
}



}