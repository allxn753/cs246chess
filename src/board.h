#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "tile.h"
#include "piece.h"

using namespace std;

class Board {

    private:
        vector<Tile> tiles;
        
    public:

        class Iterator {
            Board* board;
            size_t currIndex;
            Iterator(Board* board, size_t currIndex);

            public:
                bool operator!=(const Iterator& other);
                Tile& operator*() const;
                Iterator& operator++();
        };

        void addPiece(Piece, Tile);
        void removePiece(Tile);
        bool validBoard();
        Iterator begin() const;
        Iterator end() const;
};

#endif
