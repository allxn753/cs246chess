#include <iostream>
#include <sstream>
#include <string>
#include "game.h"
#include "board.h"
#include "piece.h"
#include "textDisplay.h"
#include "blank.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"

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

  Piece* pieces = new Blank;
  TextDisplay* textDisplay;

  Board board{pieces};
  textDisplay = new TextDisplay(&board);
  Game game{&board};

  while (cin >> command) {
    if (command == "game") {
      // starting a new game
      cin >> arg1 >> arg2; // white-player black-player

      if (arg1 == arg2 && arg1 == "human") {
        game.reset();
        board.display();
      }

      else {
        cout << "Invalid arguments for game command" << endl;
        continue;
      }
    }

    else if (command == "resign") {
      // calling resign function to end game
      cout << "resign" << endl;
      break;
    } else if (command == "threat") {
      // move pieces on the board
      cin >> arg1; // >> piece; // start end promotion (e7 e8 Q)
      cerr << arg1 << " threatened: " << game.isThreatened(arg1) << endl;
      board.display();
    } else if (command == "move") {
      // move pieces on the board
      cin >> arg1 >> arg2; // >> piece; // start end promotion (e7 e8 Q)
      if(game.validMove(arg1, arg2)) {
        Piece* p = board.getPiece(arg1);
        board.removePiece(arg2);
        p->move(arg2);
        game.nextTurn();
        board.display();
      } else { cout << "Invalid move" << endl; }
    }    
    else if (command == "setup") {
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
        } else if (command == "p") {
          cin >> arg1;
          board.print(arg1);
        }
        
        else if (command == "done") {
          break;
        } else { cout << "Invalid command" << endl; }
      }
    } // setup mode
    else if (command == "wipe") {
      game.getBoard()->wipe();
      board.display();
    }
    else { cout << "Invalid command" << endl; }

  } // while
  // output score!!
  board.detach(textDisplay);
} // main
