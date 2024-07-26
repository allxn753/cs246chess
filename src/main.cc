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
  Piece* pieces = new Blank;
  TextDisplay* textDisplay;
  Player *white, *black;
  Board board{pieces};
  textDisplay = new TextDisplay(&board);
  Game game{&board};

  while (cin >> command) {
    if (command == "game") {
      // starting a new game
      cin >> arg1 >> arg2; // white-player black-player
      if (arg1 == "human") white = new Human("white", &game);
      else if (arg1.substr(0, arg1.size() - 3) == "computer") white = new Computer("white", &game, stoi(arg1.substr(9, arg1.size() - 10)));
      else {std::cout << "Invalid arguments for game command" << endl; continue;}
      if (arg2 == "human") black = new Human("black", &game);
      else if (arg2.substr(0, arg2.size() - 3) == "computer") black = new Computer("black", &game, stoi(arg2.substr(9, arg2.size() - 10)));
      else {delete white; std::cout << "Invalid arguments for game command" << endl; continue;}

      game.reset();
      board.display();

      while(game.getState() != game.GAME_END) {
        if (game.getState() == game.WHITE_TURN) {
            white->makeMove();
        }
        else if (game.getState() == game.BLACK_TURN) {
            black->makeMove();
        }
        game.updateGameState(white, black);
      }
    }
    else if (command == "setup") {
      game.reset(true);
      while (cin >> command) {
        if (command == "+") {
          cin >> piece >> arg2; // piece end (K e1)
          board.addPiece(piece, arg2);
          board.display();
        } else if (command == "-") {
          cin >> arg1; // end (e1)
          board.removePiece(arg1);
          board.display();
        } else if (command == "=") {
          cin >> arg1; // colour (black)
          if (arg1 != "white" && arg1 != "black") {
            std::cout << "Invalid colour" << endl; continue;
          } else {
            game.setState(arg1);
          }          
        } else if (command == "p") {
          cin >> arg1;
          board.print(arg1);
        } else if (command == "done") { // done
          if(game.validSetup()) break;
          else {cerr << "Invalid setup" << endl; continue;}
        } else { std::cout << "Invalid command: 2" << endl; } //invalid command
      }
    } // setup mode
    else { std::cout << "Invalid command: 1" << endl; }

  } // while
  std::cout << "Final Score:" << endl << "White: " << white->getScore() << endl << "Black: " <<  black->getScore() << endl;
  board.detach(textDisplay);
} // main
