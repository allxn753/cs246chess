#include "queen.h"

Piece* Queen::pieceAt(int row, int col) {
    if (row == y && col == x) return this;
    else return piece->pieceAt(row, col);
}

char Queen::getChar() {
    if (colour == "white") return 'q';
    else return 'Q';
}
