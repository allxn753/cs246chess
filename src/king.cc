#include "king.h"

Piece* King::pieceAt(int row, int col) {
    if (row == y && col == x) return this;
    else return piece->pieceAt(row, col);
}

char King::getChar() {
    if (colour == "white") return 'k';
    else return 'K';
}
