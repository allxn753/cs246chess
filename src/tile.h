#ifndef TILE_H
#define TILE_H

#include <vector>
#include "piece.h"

using namespace std;

class Tile {
    
    public:
        vector<int> coordinates;
        Piece* piece;
        
        Tile(int x, int y);
        ~Tile();
        void draw();
        void addPiece(Piece);
        void removePiece();
        bool isThreatened();
};

#endif
