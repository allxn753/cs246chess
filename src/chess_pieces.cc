#include "chess_pieces.h"

Bishop::Bishop(Piece *piece, int x, int y, unsigned int val, string colour) 
: Decorator{piece, x, y, val, colour} {type = 'b';}

Knight::Knight(Piece *piece, int x, int y, unsigned int val, string colour) 
: Decorator{piece, x, y, val, colour}{type = 'n';}

King::King(Piece *piece, int x, int y, unsigned int val, string colour) 
: Decorator{piece, x, y, val, colour} {type = 'k';}


Pawn::Pawn(Piece *piece, int x, int y, unsigned int val, string colour): Decorator{piece, x, y, val, colour} {type = 'p';}

Queen::Queen(Piece *piece, int x, int y, unsigned int val, string colour) 
: Decorator{piece, x, y, val, colour} {type = 'q';}

Rook::Rook(Piece *piece, int x, int y, unsigned int val, string colour) 
: Decorator{piece, x, y, val, colour} {type = 'r';}

