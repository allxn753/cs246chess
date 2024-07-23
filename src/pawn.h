#ifndef PAWN_H
#define PAWN_H

#include "piece.h"
#include <string>

class Pawn : public Piece {
    bool hasMoved;
    public:
        bool isValidMove(Tile);
        explicit Pawn(string colour);
        ~Pawn();
        void draw();
};

#endif
