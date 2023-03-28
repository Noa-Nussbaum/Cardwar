#include "doctest.h"
#include "sources/card.hpp"
#include "sources/game.hpp"
#include "sources/player.hpp"
#include <stdexcept>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN


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

    Player player1("Noa");
    Player player2("Hodaya");

    Game Game(player1,player2);
    for(int i=0; i<7;i++){
        Game.playTurn();
    }

    CHECK(player1.stacksize()<=19);
    CHECK(player2.stacksize()<=19);

    Game.playAll();

    CHECK(player1.stacksize()==0);
    CHECK(player2.stacksize()==0);
    
}

TEST_CASE("Check winners"){

    Player player1("Noa");
    Player player2("Hodaya");

    Game Game(player1,player2);

    CHECK_THROWS(Game.printWiner());

    Game.playAll();

    // check throws for play turn after play all
    CHECK_THROWS(Game.playTurn());

     // check if print equals the winner
    int one = player1.cardesTaken();
    int two = player2.cardesTaken();

    // Save the current standard output stream to a variable
    std::stringstream ss;
    std::streambuf* old_cout_buf = std::cout.rdbuf();
    std::cout.rdbuf(ss.rdbuf());

    // Call the function that prints to standard output
    Game.printWiner();

    // Restore the original standard output stream
    std::cout.rdbuf(old_cout_buf);
    std::string output = ss.str();

    if(one>two){
        // Check that the output is correct
        CHECK(output == "Noa\n");
    }
    else{
        // Check that the output is correct
        CHECK(output == "Hodaya\n");
    }
}

TEST_CASE("Print last turn"){

    Player player1("Noa");
    Player player2("Hodaya");

    Game Game(player1,player2);

    // Save the current standard output stream to a variable
    std::stringstream ss;
    std::streambuf* old_cout_buf = std::cout.rdbuf();
    std::cout.rdbuf(ss.rdbuf());

    // Call the function that prints to standard output
    Game.printLastTurn();

    // Restore the original standard output stream
    std::cout.rdbuf(old_cout_buf);
    std::string output = ss.str();

    CHECK(output == "\n");

}
TEST_CASE("Print log"){

    Player player1("Noa");
    Player player2("Hodaya");

    Game Game(player1,player2);

    // Save the current standard output stream to a variable
    std::stringstream ss;
    std::streambuf* old_cout_buf = std::cout.rdbuf();
    std::cout.rdbuf(ss.rdbuf());

    // Call the function that prints to standard output
    Game.printLog();

    // Restore the original standard output stream
    std::cout.rdbuf(old_cout_buf);
    std::string output = ss.str();

    CHECK(output == "\n");

}

TEST_CASE("Print stats"){

    Player player1("Noa");
    Player player2("Hodaya");

    Game Game(player1,player2);

    // Save the current standard output stream to a variable
    std::stringstream ss;
    std::streambuf* old_cout_buf = std::cout.rdbuf();
    std::cout.rdbuf(ss.rdbuf());

    // Call the function that prints to standard output
    Game.printStats();

    // Restore the original standard output stream
    std::cout.rdbuf(old_cout_buf);
    std::string output = ss.str();

    CHECK(output == "\n");

}

}
