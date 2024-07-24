#include "blank.h"

Piece* Blank::pieceAt(int row, int col) {

    if ((row + col) % 2 == 0) type = ' ';
    else type = '_';

    return this;
}

char Blank::getChar() {
    return type;
}
