#include "rook.h"

Rook::Rook(Piece *piece, int x, int y, unsigned int val, string colour) 
: Decorator{piece}, x{x}, y{y}, val{val}, colour{colour} {}

Piece* Rook::pieceAt(int row, int col) {
    if (row == y && col == x) return this;
    else return piece->pieceAt(row, col);
}

char Rook::getChar() {
    if (colour == "white") return type;
    else return toupper(type);
}

bool Rook::getHasMoved() { return hasMoved; }

void Rook::setCoordinates(int x, int y) {this->x = x; this->y = y; hasMoved = true;} ;
