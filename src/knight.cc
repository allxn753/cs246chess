#include "knight.h"

Knight::Knight(Piece *piece, int x, int y, unsigned int val, string colour) 
: Decorator{piece, x, y, val, colour}{type = 'n';}
