#ifndef KING_H
#define KING_H

#include "piece.h"
#include <string>

class King : public Piece {
    bool hasMoved;
    public:
        bool isValidMove(Tile);
        explicit King(string colour);
        ~King();
        void draw();
};

#endif
