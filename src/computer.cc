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

        while (!success) {

            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    if (game->validMove(convertPosition(piece->getX(), piece->getY()), convertPosition(i, j))) {
                        piece->move(i, j);
                        success = true;
                        break;
                    }

                    if (success) {break;}
                }

                if (success) {break;}
            }
            piece = getRandomPiece(playerColour, game, numPieces);
        }

    }

}
