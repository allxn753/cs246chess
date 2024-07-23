#include "board.h"

Board::Board(bool setup) {
        
    for (int i = 0; i < BOARD_DIMENSION; i++) {
        vector<Tile> v1;
        for (int j = 0; i < BOARD_DIMENSION; j++) {
            v1.push_back(Tile(i, j));
        }
        tiles.push_back(v1);
    }

    if (!setup) {

    }

}
