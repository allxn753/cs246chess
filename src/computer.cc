#include "computer.h"
#include "helpers.h"
#include <stdlib.h>
#include <time.h> 

Decorator* getRandomPiece(string playerColour, Game* game, int numPieces) {    
    srand (time(NULL));    
    int x = rand() % numPieces;
    while (game->getBoard()->getArr()[x]->getColour() != playerColour) {
        x = rand() % numPieces;
    }
    return game->getBoard()->getArr()[x];

}

Computer::Computer(string playerColour, Game* game, int level) : Player{playerColour, game}, level{level} {}

void Computer::makeMove() const {

    if (level == 1) {
        int numPieces = game->getBoard()->getNumPieces();
        vector<Decorator*> arr = game->getBoard()->getArr();
        bool success = false;
        Decorator* piece;
        string arg1, arg2;
        while (!success) {
            // cerr << "Trying new piece" << endl;
            piece = getRandomPiece(playerColour, game, numPieces);
            arg1 = convertPosition(piece->getX(), piece->getY());
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    arg2 = convertPosition(i, j);
                    // cerr << arg1 << " " << arg2 << endl;
                    if (game->validMove(arg1, arg2)) {
                        // Is player in check after move
                        Piece * p1 = game->getBoard()->getPiece(arg1);
                        Piece * p2 = game->getBoard()->getPiece(arg2);
                        if (p2->getChar() != ' ' && p2->getChar() != '_') {
                            p2->move(-1, -1); // "store" p2 on an unused tile
                        }
                        p1->move(arg2);
                        game->updateCheck();
                        p1->move(arg1);
                        p2->move(arg2);
                        if (game->getCheck()) {
                            game->updateCheck();
                        } else {
                            game->updateCheck();
                            game->performMove(arg1, arg2);
                            success = true;
                        }                       
                    } else {
                        // cerr << "Invalid computer move" << endl;
                    }
                    if (success) break;
                } // for (j)
                if (success) break;
            } // for (i)            
        }
    }
}
