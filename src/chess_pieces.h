#ifndef CHESS_PIECES_H
#define CHESS_PIECES_H

#include "decorator.h"

class Bishop : public Decorator {
    public:
        Bishop(Piece *piece, int x, int y, unsigned int val, string colour);
};

class Knight : public Decorator {
    public:
        Knight(Piece *piece, int x, int y, unsigned int val, string colour);
};

class King : public Decorator {
    public:
        King(Piece *piece, int x, int y, unsigned int val, string colour);
};

class Pawn : public Decorator {
    public:
        Pawn(Piece *piece, int x, int y, unsigned int val, string colour);
};

class Queen : public Decorator {
    public:
        Queen(Piece *piece, int x, int y, unsigned int val, string colour);
};

class Rook : public Decorator {
    public:
        Rook(Piece *piece, int x, int y, unsigned int val, string colour);
};


#endif
