#include "bishop.h"

Bishop::Bishop(Piece *piece, int x, int y, unsigned int val, string colour) 
: Decorator{piece}, x{x}, y{y}, val{val}, colour{colour} {}

Piece* Bishop::pieceAt(int row, int col) {
    if (row == y && col == x) return this;
    else return piece->pieceAt(row, col);
}

char Bishop::getChar() {
    if (colour == "white") return type;
    else return toupper(type);
}

void Bishop::setCoordinates(int x, int y) {this->x = x; this->y = y;}

bool Bishop::getHasMoved() {return hasMoved;}
