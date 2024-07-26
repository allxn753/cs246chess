#include <iostream>
#include <sstream>
#include <string>
#include "game.h"
#include "board.h"
#include "player.h"
#include "computer.h"
#include "piece.h"
#include "textDisplay.h"
#include "blank.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
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

      if (arg1 == arg2) {
        if (arg1 == "human"){
          game.reset();
          board.display();
        }
      }

      else if (arg1 == "human" && arg2.substr(0, arg2.size() - 3) == "computer") {
        //Player* black = new Computer("black", &game, stoi(arg2.substr(9, arg2.size() - 10)));
      }

      else if (arg2 == "human" && arg1.substr(0, arg1.size() - 3) == "computer") {
        Player* white = new Computer("white", &game, stoi(arg1.substr(9, arg1.size() - 10)));

        game.reset();
        board.display();

        while(game.getState() != game.GAME_END) {

          white->makeMove();
          board.display();
          game.nextTurn();
          game.updateCheck();

          while(cin >> command) {
            if (command == "move") {
              // move pieces on the board
              cin >> arg1 >> arg2; // >> piece; // start end promotion (e7 e8 Q)
              if(game.validMove(arg1, arg2)) {
                if (game.isCastling(arg1, arg2) == 1) {
                  string arg3 = arg1;
                  arg3[0] = 'h';
                  Piece* r = board.getPiece(arg3);
                  arg3[0] = arg1[0] + 1;
                  r->move(arg3);
                } else if (game.isCastling(arg1, arg2) == -1) {
                  string arg3 = arg1;
                  arg3[0] = 'a';
                  Piece* r = board.getPiece(arg3);
                  arg3[0] = arg1[0] - 1;
                  r->move(arg3);
                }
                if (game.isEnPassant(arg1, arg2) == 1) {
                  string arg3 = arg2;
                  arg3[1] = arg2[1] - 1;
                  board.removePiece(arg3);
                }
                else if (game.isEnPassant(arg1, arg2) == -1) {
                  string arg3 = arg2;
                  arg3[1] = arg2[1] + 1;
                  board.removePiece(arg3);
                }
                board.getArr()[0]->setEnPassant({8, 8});
                if (game.isSkipping(arg1, arg2) == 1) {
                  string arg3 = arg1;
                  arg3[1] = arg1[1] + 1;
                  board.getPiece(arg3)->setEnPassant(convertPosition(arg3));
                } else if (game.isSkipping(arg1, arg2) == -1) {
                  string arg3 = arg1;
                  arg3[1] = arg1[1] - 1;
                  board.getPiece(arg3)->setEnPassant(convertPosition(arg3));
                }
                Piece* p = board.getPiece(arg1);
                board.removePiece(arg2);
                p->move(arg2);
                game.nextTurn();  
                board.display();
                game.updateCheck();
                // Checkmate
                if (game.isCheckmate() && (game.whoseTurn() == "white")) {
                  cout << "Checkmate! Black wins!" << endl;
                } else if (game.isCheckmate()) cout << "Checkmate! Black wins!" << endl;

                // Check
                if (game.getCheck() && game.whoseTurn() == "white") {
                  cout << "White is in check." << endl;
                } else if (game.getCheck()) cout << "Black is in check." << endl;
              } else { cout << "Invalid move" << endl; }
              break;
            } else {cout << "Invalid command" << endl;}
          }
        }
        
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
        if (game.isCastling(arg1, arg2) == 1) {
          string arg3 = arg1;
          arg3[0] = 'h';
          Piece* r = board.getPiece(arg3);
          arg3[0] = arg1[0] + 1;
          r->move(arg3);
        } else if (game.isCastling(arg1, arg2) == -1) {
          string arg3 = arg1;
          arg3[0] = 'a';
          Piece* r = board.getPiece(arg3);
          arg3[0] = arg1[0] - 1;
          r->move(arg3);
        }
        if (game.isEnPassant(arg1, arg2) == 1) {
          string arg3 = arg2;
          arg3[1] = arg2[1] - 1;
          board.removePiece(arg3);
        }
        else if (game.isEnPassant(arg1, arg2) == -1) {
          string arg3 = arg2;
          arg3[1] = arg2[1] + 1;
          board.removePiece(arg3);
        }
        board.getArr()[0]->setEnPassant({8, 8});
        if (game.isSkipping(arg1, arg2) == 1) {
          string arg3 = arg1;
          arg3[1] = arg1[1] + 1;
          board.getPiece(arg3)->setEnPassant(convertPosition(arg3));
        } else if (game.isSkipping(arg1, arg2) == -1) {
          string arg3 = arg1;
          arg3[1] = arg1[1] - 1;
          board.getPiece(arg3)->setEnPassant(convertPosition(arg3));
        }
        Piece* p = board.getPiece(arg1);
        board.removePiece(arg2);
        p->move(arg2);
        game.nextTurn();  
        board.display();
        game.updateCheck();
        // Checkmate
        if (game.isCheckmate() && (game.whoseTurn() == "white")) {
          cout << "Checkmate! Black wins!" << endl;
        } else if (game.isCheckmate()) cout << "Checkmate! Black wins!" << endl;

        // Check
        if (game.getCheck() && game.whoseTurn() == "white") {
          cout << "White is in check." << endl;
        } else if (game.getCheck()) cout << "Black is in check." << endl;
      } else { cout << "Invalid move" << endl; }
    }    
    else if (command == "setup") {
      board.wipe();
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
        } else if (command == "done") {
          break;
        } else { cout << "Invalid command" << endl; }
      }
    } // setup mode
    else { cout << "Invalid command" << endl; }

  } // while

  //  output score /*
  // score.print()?
  // */
  board.detach(textDisplay);
} // main
