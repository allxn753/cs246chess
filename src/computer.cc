#include "computer.h"
#include "helpers.h"
#include <stdlib.h>
#include <time.h> 

Decorator* getRandomPiece(string playerColour, Game* game, int numPieces) {    
    srand (time(NULL));    
    int x = rand() % numPieces;
    int count = 0;
    while (game->getBoard()->getArr()[x]->getColour() != playerColour) {
        x = (rand() + count) % numPieces;
        ++count;
    }
    return game->getBoard()->getArr()[x];

}

Computer::Computer(string playerColour, Game* game, int level) : Player{playerColour, game}, level{level} {}

void Computer::makeMove() const {
    string command;
    cin >> command;
    if (command != "move") {
        cerr << "Invalid Command" << endl;
        makeMove();
    }
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
                    if (game->validMove(arg1, arg2)) {
                        cerr << arg1 << " " << arg2 << endl;
                        // Is player in check after move
                        Piece * p1 = game->getBoard()->getPiece(arg1);
                        Piece * p2 = game->getBoard()->getPiece(arg2);
                        p1->move(arg2);
                        p2->move(-1, -1);
                        game->updateCheck();
                        p1->move(arg1);
                        p2->move(arg2);
                        if (game->getCheck()) {
                            game->updateCheck();
                            continue;
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
