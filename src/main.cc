#include <iostream>
#include <sstream>
#include <string>
#include "game.h"
#include "board.h"
#include "textDisplay.h"
#include "blank.h"
using namespace std;

// Test harness for Chess functions. We assume that all commands entered are valid.
// Valid commands: game <whitePlayer> <blackPlayer>,
//                 move <start> <end> <promotion>,
//                 setup, + <piece> <square>, - <square>,
//                 = <colour>, done, resign
// Silently ignores invalid commands.

int main() { 
  
  string command, arg1, arg2;
  char piece;
  int x, y;
  bool setupMode = false;
  Game* game = new Game(new Blank());

  while (cin >> command) {
    if (command == "game") {
      // starting a new game
      cin >> arg1 >> arg2; // white-player black-player
      cout << "test" << arg1 << arg2 << endl;
    }

    else if (command == "resign") {
      // calling resign function to end game
      cout << "resign" << endl;
      break;
    }

    else if (command == "move") {
      // move pieces on the board
      cin >> arg1 >> arg2 >> piece; // start end promotion (e7 e8 Q)
    }
    
    else if (command == "setup") {
      while (cin >> command) {
        if (command == "+") {
          cin >> piece >> arg2; // piece end (K e1)
          game->addPiece(piece, arg2);
          game->display();
        } else if (command == "-") {
          cin >> arg1; // end (e1)
        } else if (command == "=") {
          cin >> arg1; // colour (black)
        } else if (command == "done") {
          break;
        } else { cout << "Invalid command" << endl; }
      }
    } // setup mode
    else { cout << "Invalid command" << endl; }

  } // while
  // output score!!
} // main
