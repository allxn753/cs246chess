#include "knight.h"

Knight::Knight(Piece *piece, int x, int y, unsigned int val, string colour) 
: Decorator{piece}, x{x}, y{y}, val{val}, colour{colour} {}

Piece* Knight::pieceAt(int row, int col) {
    if (row == y && col == x) return this;
    else return piece->pieceAt(row, col);
}

char Knight::getChar() {
    if (colour == "white") return type;
    else return toupper(type);
}

bool Knight::getHasMoved() { return hasMoved; }

void Knight::setCoordinates(int x, int y) {this->x = x; this->y = y;} ;
