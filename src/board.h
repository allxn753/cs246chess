#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
#include "subject.h"
#include "piece.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "king.h"
#include "queen.h"
#include "game.h"

class Piece;

using namespace std;

class Board : public Subject {
    protected:
        Piece* pieces;

    public:
        inline static int HEIGHT = 8;
        inline static int WIDTH = 8;
        
        explicit Board(Piece* pieces) : pieces{pieces} {};
        Piece*& boardState() { return pieces; }
        void display();

        void addPiece(char type, string pos);
        void removePiece(string pos);
        Piece* getPiece(int x, int y) const override;

        ~Board();
};


#endif
