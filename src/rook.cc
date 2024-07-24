#include "rook.h"

Piece* Rook::pieceAt(int row, int col) {
    if (row == y && col == x) return this;
    else return piece->pieceAt(row, col);
}

char Rook::getChar() {
    if (colour == "white") return 'r';
    else return 'R';
}
