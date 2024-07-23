#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"
#include <string>

class Knight : public Piece {
    public:
        bool isValidMove(Tile);
        explicit Knight(string colour);
        ~Knight();
        void draw();
};

#endif
