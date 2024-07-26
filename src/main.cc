#include <iostream>
#include <sstream>
#include <string>
#include "game.h"
#include "computer.h"
#include "human.h"
#include "textDisplay.h"
#include "blank.h"
#include "helpers.h"

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
  bool setup = false;  
  Player *white, *black;
  Piece* p = new Blank;
  Board* b = new Board{p};
  Game game{b};
  TextDisplay* textDisplay = new TextDisplay(game.getBoard());
  while (cin >> command) {
    if (command == "game") {
      // starting a new game
      cin >> arg1 >> arg2; // white-player black-player
      if (!setup) game.reset();
      if (arg1 == arg2) {
        if (arg1 == "human"){
          white = new Human("white", &game);
          black = new Human("black", &game);
          game.gameLoop(white, black);
        }

        if (arg1.substr(0, arg1.size() - 3) == "computer"){
          white = new Computer("white", &game, stoi(arg1.substr(9, arg2.size() - 10)));
          black = new Computer("black", &game, stoi(arg2.substr(9, arg2.size() - 10)));
          game.gameLoop(white, black);
        }
      }

      else if (arg1 == "human" && arg2.substr(0, arg2.size() - 3) == "computer") {
        white = new Human("white", &game);
        black = new Computer("black", &game, stoi(arg2.substr(9, arg2.size() - 10)));
        game.gameLoop(white, black);

      }

      else if (arg2 == "human" && arg1.substr(0, arg1.size() - 3) == "computer") {
        white = new Computer("white", &game, stoi(arg1.substr(9, arg1.size() - 10)));
        black = new Human("black", &game);
        game.gameLoop(white, black);        
      }
      else {
        cout << "Invalid arguments for game command" << endl;
        continue;
      }
    }
    else if (command == "setup") {
      game.reset(true);
      setup = true;
      while (cin >> command) {
        if (command == "+") {
          cin >> piece >> arg2; // piece end (K e1)
          game.getBoard()->addPiece(piece, arg2);
          game.getBoard()->display();
        } else if (command == "-") {
          cin >> arg1; // end (e1)
          game.getBoard()->removePiece(arg1);
          game.getBoard()->display();
        } else if (command == "=") {
          cin >> arg1; // colour (black)
          if (arg1 != "white" && arg1 != "black") {
            std::cout << "Invalid colour" << endl; continue;
          } else {
            game.setState(arg1);
          }          
        } else if (command == "p") {
          cin >> arg1;
          game.getBoard()->print(arg1);
        } else if (command == "done") { // done
          if(game.validSetup()) break;
          else {cerr << "Invalid setup" << endl; continue;}
        } else { std::cout << "Invalid command: 2" << endl; } //invalid command
      }
    } // setup mode
    else { std::cout << "Invalid command: 1" << endl; }

  } // while
  if (white && black) std::cout << "Final Score:" << endl << "White: " << white->getScore() << endl << "Black: " << black->getScore() << endl;
  game.getBoard()->detach(textDisplay);
  delete white;
  delete black;
} // main
