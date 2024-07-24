#include "pawn.h"

Piece* Pawn::pieceAt(int row, int col) {
    if (row == y && col == x) return this;
    else return piece->pieceAt(row, col);
}

char Pawn::getChar() {
    if (colour == "white") return 'p';
    else return 'P';
}
