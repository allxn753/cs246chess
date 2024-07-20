#ifndef TILE_H
#define TILE_H

#include <vector>
#include "piece.h"

using namespace std;

class Tile {
    
    public:
        vector<int> coordinates;
        void draw();
        void addPiece(Piece);
        void removePiece();
        bool isThreatened();
};

#endif
