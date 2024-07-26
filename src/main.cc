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
  float blackPoints, whitePoints;
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
        Player* black = new Human("black", &game);

        game.reset();
        board.display();

        while(game.getState() != game.GAME_END) {
          if (game.getState() == game.WHITE_TURN) {
            white->makeMove();
            cout << "white";
          }

          else if (game.getState() == game.BLACK_TURN) {
            black->makeMove();
            cout << "black";
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
      if (game.whoseTurn() == "white") {
        cout << "Checkmate! Black wins!" << endl;
        ++blackPoints;
      } else {
        cout << "Checkmate! White wins!" << endl;
        ++whitePoints;
      }
      game.reset();
      continue;
    } else if (command == "threat") {
      // move pieces on the board
      cin >> arg1; // >> piece; // start end promotion (e7 e8 Q)
      cerr << arg1 << " threatened: " << game.isThreatened(arg1) << endl;
      board.display();
    } else if (command == "move") {
      // move pieces on the board
      cin >> arg1 >> arg2; // >> piece; // start end promotion (e7 e8 Q)
      if(game.validMove(arg1, arg2)) {        
        // Is player in check after move
        Piece * p1 = game.getBoard()->getPiece(arg1);
        Piece * p2 = game.getBoard()->getPiece(arg2);
        if (p2->getChar() != ' ' && p2->getChar() != '_') {
          p2->move(-1, -1); // "store" p2 on an unused tile
        }
        p1->move(arg2);
        game.updateCheck();
        p1->move(arg1);
        p2->move(arg2);
        if (game.getCheck()) {
          game.updateCheck();
          cout << "Invalid move: Move causes player to be in check" << endl;
          continue;        
        }
        game.updateCheck();
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

        if (game.isPromoting(arg1, arg2)) {
          cout << "Pawn promotion! Choose a piece: (q, r, b, n)" << endl;
          char promo;
          while (cin >> promo) {
            promo = tolower(promo);
            if (promo != 'q' && promo != 'r' && promo != 'b' && promo != 'n') {
              cout << "Invalid promotion" << endl;
            } else {
              board.removePiece(arg2);
              if (isupper(board.getPiece(arg1)->getChar())) {
                board.addPiece(toupper(promo), arg2);
              } else {
                board.addPiece(promo, arg2);
              }
              board.removePiece(arg1);
              break;
            }
          }
        } else {
          Piece* p = board.getPiece(arg1);
          board.removePiece(arg2);
          p->move(arg2);
        }
        
        game.nextTurn();  
        board.display();
        game.updateCheck();
        // Checkmate
        if (game.isCheckmate()) {
          if (game.whoseTurn() == "white") {
            cout << "Checkmate! Black wins!" << endl;
            ++blackPoints;
          } else {
            cout << "Checkmate! White wins!" << endl;
            ++whitePoints;
          }
          game.reset();
          continue;
        }
        // Check
        if (game.getCheck() && game.whoseTurn() == "white") {
          cout << "White is in check." << endl;
        } else if (game.getCheck()) cout << "Black is in check." << endl;
      } else { cout << "Invalid move" << endl; }
    }    
    else if (command == "setup") {
      board.wipe();
      game.setState("white");
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
            cout << "Invalid colour" << endl; continue;
          } else {
            game.setState(arg1);
          }          
        } else if (command == "p") {
          cin >> arg1;
          board.print(arg1);
        } else if (command == "done") { // done
          if(game.validSetup()) break;
          else {cerr << "Invalid setup" << endl; continue;}
        } else { cout << "Invalid command" << endl; } //invalid command
      }
    } // setup mode
    else { cout << "Invalid command" << endl; }

  } // while

  cout << "Final Score:" << endl << "White: " << whitePoints << endl << "Black: " << blackPoints << endl;
  board.detach(textDisplay);
} // main
