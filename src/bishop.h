#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"
#include <string>

class Bishop : public Piece {
    public:
        bool isValidMove(Tile);
        explicit Bishop(string colour);
        ~Bishop();
        void draw();
};

#endif
