#include "queen.h"

Queen::Queen(Piece *piece, int x, int y, unsigned int val, string colour) 
: Decorator{piece}, x{x}, y{y}, val{val}, colour{colour} {}

Piece* Queen::pieceAt(int row, int col) {
    if (row == y && col == x) return this;
    else return piece->pieceAt(row, col);
}

char Queen::getChar() {
    if (colour == "white") return type;
    else return toupper(type);
}

void Queen::setCoordinates(int x, int y) {this->x = x; this->y = y;}

bool Queen::getHasMoved() {return hasMoved;}
