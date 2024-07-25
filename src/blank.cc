#include "blank.h"
#include "helpers.h"

Piece* Blank::pieceAt(int x, int y) {

    if ((x+y) % 2 == 0) type = ' ';
    else type = '_';

    return this;
}

char Blank::getChar() {
    return type;
}

bool Blank::getHasMoved() {return false;}

Piece* Blank::pieceAt(string pos) {
    vector<int> coord = convertPosition(pos);
    return pieceAt(coord[0], coord[1]);
}