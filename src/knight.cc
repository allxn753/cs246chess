#include "knight.h"

Piece* Knight::pieceAt(int row, int col) {
    if (row == y && col == x) return this;
    else return piece->pieceAt(row, col);
}

char Knight::getChar() {
    if (colour == "white") return 'n';
    else return 'N';
}
