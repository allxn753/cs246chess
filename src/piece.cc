#include "piece.h"

Piece::Piece(Board * component, char type, int x, int y): component{component}, type{type}, x{x}, y{y} {}

char Piece::pieceAt(int x, int y) {
    if(this->x == x && this->y == y) return type;
    return component->pieceAt(x, y);
}

Piece::~Piece(){delete component;}