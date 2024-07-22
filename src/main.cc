#include <iostream>
#include <sstream>
#include <string>
#include "game.h"
#include "board.h"
#include "textDisplay.h"
using namespace std;

// Test harness for Chess functions. We assume that all commands entered are valid.
// Valid commands: game <whitePlayer> <blackPlayer>,
//                 move <start> <end> <promotion>,
//                 setup, + <piece> <square>, - <square>,
//                 = <colour>, done, resign
// Silently ignores invalid commands.

int main() { 
  
  string input;

  while (getline(cin, input)) {
  
    istringstream iss(input);
    string command;
    iss >> command;
    
    if (command == "game") {
      // starting a new game
      string whitePlayer, blackPlayer;
      iss >> whitePlayer >> blackPlayer;

      cout << "test" << whitePlayer << blackPlayer << endl;
    }

    else if (command == "resign") {
      // calling resign function to end game
      break;
    }

    else if (command == "move") {
      // move pieces on the board
      string start, end, promotion;
      iss >> start >> end >> promotion;

      cout << "test" << start << end << promotion << endl;
    }
    
    else if (command == "setup") {
      cout << "test" << endl;
    }

    else if (command == "+") {
      string piece, square;
      iss >> piece >> square;

      cout << "hi" << piece << square << endl;
    }

    else if (command == "-") {
      string square;
      iss >> square;

      cout << square << endl;
    }

    else if (command == "=") {
      string colour;
      iss >> colour;

      cout << colour << endl;
    }

    else if (command == "done") {
      
      cout << "domnfwwfwef" << endl;
    }

    else { cout << "Invalid command" << endl; }

  } // while

} // main
