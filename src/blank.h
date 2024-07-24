#ifndef BLANK_H
#define BLANK_H
#include "piece.h"
#include <iostream>

class Blank: public Piece {
  protected:
    bool enPassant;
    char type;
  public:
    Piece* pieceAt(int x, int y) override;
    char getChar() override;
    void setEnPassant(bool tf) { enPassant = tf; };
    bool getEnPassant() { return enPassant; };
    bool getHasMoved() override;
};

#endif
