#include "board.h"


Board::~Board(){}

// #include "rook.h"
// #include "knight.h"
// #include "queen.h"
// #include "king.h"
// #include "bishop.h"
// #include "pawn.h"



// Board::Board(bool setup) {
        
//     for (int i = 0; i < BOARD_DIMENSION; i++) {
//         vector<Tile> v1;
//         for (int j = 0; j < BOARD_DIMENSION; j++) {
//             v1.push_back(Tile(i, j));
//         }
//         tiles.push_back(v1);
//     }

//     if (!setup) {
//         tiles[0][0].addPiece(new Rook("black"));
//         tiles[0][1].addPiece(new Knight("black"));
//         tiles[0][2].addPiece(new Bishop("black"));
//         tiles[0][3].addPiece(new Queen("black"));
//         tiles[0][4].addPiece(new King("black"));
//         tiles[0][5].addPiece(new Bishop("black"));
//         tiles[0][6].addPiece(new Knight("black"));
//         tiles[0][7].addPiece(new Rook("black"));

//         for (int i = 0; i < BOARD_DIMENSION; i++) {
//             tiles[1][i].addPiece(new Pawn("black"));
//             tiles[6][i].addPiece(new Pawn("white"));
//         }

//         tiles[7][0].addPiece(new Rook("white"));
//         tiles[7][1].addPiece(new Knight("white"));
//         tiles[7][2].addPiece(new Bishop("white"));
//         tiles[7][3].addPiece(new Queen("white"));
//         tiles[7][4].addPiece(new King("white"));
//         tiles[7][5].addPiece(new Bishop("white"));
//         tiles[7][6].addPiece(new Knight("white"));
//         tiles[7][7].addPiece(new Rook("white"));

//     }

//}