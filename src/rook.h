#ifndef ROOK_H
#define ROOK_H

#include "piece.h"
#include <string>

class Rook : public Piece {
    bool hasMoved;
    public:
        bool isValidMove(Tile);
        explicit Rook(string colour);
        ~Rook();
        void draw();
};

#endif
