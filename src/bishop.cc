#include "bishop.h"

Piece* Bishop::pieceAt(int row, int col) {
    if (row == y && col == x) return this;
    else return piece->pieceAt(row, col);
}

char Bishop::getChar() {
    if (colour == "white") return 'b';
    else return 'B';
}
