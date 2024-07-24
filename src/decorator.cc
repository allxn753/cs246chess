#include "piece.h"
#include "decorator.h"

Decorator::Decorator(Piece* piece, int x, int y, unsigned int val, string colour) :
    piece{piece}, x{x}, y{y}, val{val}, colour{colour} {hasMoved = false;}

Decorator::~Decorator() { delete piece; }

void Decorator::setCoordinates(int x, int y) {this->x = x; this->y = y; this->hasMoved = true;} ;
