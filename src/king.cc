#include "king.h"

King::King(Piece *piece, int x, int y, unsigned int val, string colour) 
: Decorator{piece}, x{x}, y{y}, val{val}, colour{colour} {}

Piece* King::pieceAt(int row, int col) {
    if (row == y && col == x) return this;
    else return piece->pieceAt(row, col);
}

char King::getChar() {
    if (colour == "white") return type;
    else return toupper(type);
}

void King::setCoordinates(int x, int y) {this->x = x; this->y = y; hasMoved = true;} 

bool King::getHasMoved() {return hasMoved;}
