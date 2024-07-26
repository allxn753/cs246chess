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
        Decorator* piece = getRandomPiece(playerColour, game, numPieces);

        cout << convertPosition(0, 6) << endl;
        cout << convertPosition(0, 5) << endl;
        cout << game->validMove(convertPosition(0, 6), convertPosition(0, 5)) << endl;

        while (success) {

            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    if (game->validMove(convertPosition(piece->getX(), piece->getY()), convertPosition(i, j))) {
                        piece->move(i, j);
                        success = true;
                        cout << "n";
                        break;
                    }

                    if (success) {cout << "a"; break;}
                }

                if (success) {cout << "b"; break;}
            }

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
