#include "piece.h"
#include "decorator.h"

Decorator::Decorator(Piece* piece, int x, int y, unsigned int val, string colour) : piece{piece}, x{x}, y{y}, val{val}, colour{colour} {}

Decorator::~Decorator() { delete piece; }

Piece* Decorator::pieceAt(int row, int col) {
    if (row == y && col == x) return this;
    else {
        return piece->pieceAt(row, col);
    }
}

char Decorator::getChar() {
    if (colour == "white") return type;
    else return toupper(type);
}