#include "decorator.h"
#include "helpers.h"
#include <vector>


Decorator::Decorator(Piece* piece, int x, int y, unsigned int val, string colour) : piece{piece}, x{x}, y{y}, val{val}, colour{colour} {}

Decorator::~Decorator() { delete piece; }

Piece* Decorator::pieceAt(int x, int y) {
    if (this->x == x && this->y == y) return this;
    return piece->pieceAt(x, y);
}

Piece* Decorator::pieceAt(string pos) {
    vector<int> coord = convertPosition(pos);
    return pieceAt(coord[0], coord[1]);
}

char Decorator::getChar() {
    if (colour == "white") return type;
    else return toupper(type);
}