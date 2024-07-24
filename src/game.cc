#include "game.h"

Game::Game(Board* brd): theBoard{brd}{}

vector<int> Game::convertPosition(string pos) {
    int x = int(pos[0]) - 'a';
    int y = char(pos[1] - '1');
    vector<int> v = {x,y};
    return v;
}

bool Game::validMove(string pos1, string pos2) {
    gameStates state = WHITE_TURN; // placeholder enum
    vector<int> coord1 = convertPosition(pos1);
    vector<int> coord2 = convertPosition(pos2);

    if (coord1[0] < 0 || coord1[0] > 7 || coord1[1] < 0 || coord1[1] > 7 ||
        coord2[0] < 0 || coord2[0] > 7 || coord2[1] < 0 || coord2[1] > 7) return false; // return false if out of bounds of the board
    if (coord1 == coord2) return false; // no piece can move onto itself

    char activePiece = theBoard->getPiece(coord1[0], coord1[1])->getChar();
    char destination = theBoard->getPiece(coord2[0], coord2[1])->getChar();

    if (activePiece == ' ' || activePiece == '_') return false; // return false if there is no piece at the start
    if (state == WHITE_TURN && isupper(activePiece)) return false; // can only move pieces on their turn
    if (state == BLACK_TURN && !isupper(activePiece)) return false;
    if (destination != ' ' || destination != '_') {
        if (isupper(activePiece) == isupper(destination)) return false; // false if there are two of the same colour pieces
    }

    int dX;
    int dY;
    switch (tolower(activePiece)) {
        case 'k':
            if (coord2[0] > coord1[0] + 1 || coord2[0] < coord1[0] - 1 ||
                coord2[1] > coord1[1] + 1 || coord2[1] < coord1[1] - 1) return false;
            
            return true;

        case 'q':
            dX = coord2[0] - coord1[0];
            dY = coord2[1] - coord1[1];

            if (dX != 0 && dY != 0) {
                if (abs(dX) != abs(dY)) return false;
            }

            if (isPathObstructed(coord1, dX, dY)) return false;

            return true;
        
        case 'r':
            dX = coord2[0] - coord1[0];
            dY = coord2[1] - coord1[1];

            if (dX != 0 && dY != 0) return false;

            if (isPathObstructed(coord1, dX, dY)) return false;

            return true;

        case 'b':
            dX = coord2[0] - coord1[0];
            dY = coord2[1] - coord1[1];

            if (abs(dX) != abs(dY)) return false;

            if (isPathObstructed(coord1, dX, dY)) return false;

            return true;

        case 'n':
            dX = coord2[0] - coord1[0];
            dY = coord2[1] - coord1[1];

            if ((abs(dX) == 2 && abs(dY) == 1) || (abs(dX) == 1 && abs(dY) == 2)) return true;

            return false;

        case 'p':
            dX = coord2[0] - coord1[0];
            dY = coord2[1] - coord1[1];
            int yMult;

            if (isupper(activePiece)) yMult = 1;
            else yMult = -1;

            if (!theBoard->getPiece(coord1[0], coord1[1])->getHasMoved()) {
                if (dY != 1 * yMult || dY != 2 * yMult) return false;
            }
            if (dY != 1 * yMult) return false;

            if (dY != 1 * yMult) return false;
            if (dX == 0 && theBoard->getPiece(coord2[0], coord2[1])->getChar() != ' ' &&
                theBoard->getPiece(coord2[0], coord2[1])->getChar() != '_') return false;
            if (dX != 0 && (theBoard->getPiece(coord2[0], coord2[1])->getChar() == ' ' ||
                theBoard->getPiece(coord2[0], coord2[1])->getChar() == '_')) return false;

            return true;
    }
}

bool Game::isPathObstructed(vector<int> coord1, int dX, int dY) {
    int xMult;
    int yMult;
    
    if (dX > 0) xMult = 1;
    else xMult = -1;
    
    if (dY > 0) yMult = 1;
    else yMult = -1;

    if (dX == 0) {
        for (int i = 1; i < dY; i++) {    
            if (theBoard->getPiece(coord1[0], coord1[1] + i * yMult)->getChar() != ' ' &&
                theBoard->getPiece(coord1[0], coord1[1] + i * yMult)->getChar() != '_') return true;
        }
    } else if (dY == 0) {
        for (int i = 1; i < dY; i++) {
            if (theBoard->getPiece(coord1[0] + i * xMult, coord1[1])->getChar() != ' ' &&
                theBoard->getPiece(coord1[0] + i * xMult, coord1[1])->getChar() != '_') return true;
        }
    } else {
        for (int i = 1; i < dX; i++) {
            if (theBoard->getPiece(coord1[0] + i * xMult, coord1[1] + i * yMult)->getChar() != ' ' &&
                theBoard->getPiece(coord1[0] + i * xMult, coord1[1] + i * yMult)->getChar() != '_') return true;
        }
    }

    return false;
}

bool Game::isThreatened(string pos) {

}
