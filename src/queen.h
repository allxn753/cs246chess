#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"
#include <string>

class Queen : public Piece {
    public:
        bool isValidMove(Tile);
        explicit Queen(string colour);
        ~Queen();
        void draw();
};

#endif
