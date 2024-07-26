#include "computer.h"
#include "helpers.h"

Decorator* getRandomPiece(string playerColour, Game* game, int numPieces) {

    int x = rand() % numPieces;

    while (game->getBoard()->getArr()[x]->getColour() != playerColour) {
        x = rand() % numPieces;
    }

    return game->getBoard()->getArr()[x];

}

Computer::Computer(string playerColour, Game* game, unsigned int level) : Player{playerColour, game}, level{level} {}

void Computer::makeMove() const {

    if (level == 1) {

        int numPieces = game->getBoard()->getNumPieces();
        vector<Decorator*> arr = game->getBoard()->getArr();
        bool success = false;
        Decorator* piece = getRandomPiece(playerColour, game, numPieces);
        int xPos = piece->getX();
        int yPos = piece->getY();

        while (success) {
            for (int i = 0; i < numPieces; i++) {
                if (game->validMove(convertPosition(xPos, yPos), convertPosition(arr[i]->getX(), arr[i]->getY()))) {
                    piece->move(arr[i]->getX(), arr[i]->getY());
                    success = true;
                    break;
                }
            }
            piece = getRandomPiece(playerColour, game, numPieces);
        }

    }

}
