#ifndef BLANK_H
#define BLANK_H
#include "piece.h"
#include <iostream>

class Blank: public Piece {
  protected:
    bool enPassant;
  public:
    Piece* pieceAt(int x, int y) override;
    void setEnPassant(bool tf) { enPassant = tf; };
    bool getEnPassant() { return enPassant; };
};

#endif
