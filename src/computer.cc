#include "computer.h"
#include "helpers.h"

Decorator* getRandomPiece(string playerColour, Game* game, int numPieces) {

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
        int xPos, yPos;


        while (!success) {            
            piece = getRandomPiece(playerColour, game, numPieces);
            xPos = piece->getX();
            yPos = piece->getY();
            cout << "Trying to move new Piece: " << piece->getChar() << " " << xPos << "," << yPos << endl;
            for (int i = 0; i < Board::WIDTH; ++i) {
                for (int j = 0; j < Board::HEIGHT; ++j) {
                    cerr << convertPosition(i, j) << endl;
                    if (game->validMove(convertPosition(xPos, yPos), convertPosition(i, j))) {
                        cerr << "Found Move" << endl;
                        piece->move(i, j);
                        success = true;
                        break;
                    }
                }                
            }
            
        }

    }

}
