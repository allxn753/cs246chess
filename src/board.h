#ifndef BOARD_H
#define BOARD_H

#include <vector>

using namespace std;

class Board {
    public:
        inline static int HEIGHT = 8;
        inline static int WIDTH = 8;
        
        class Iterator {
            Board* board;
            size_t currIndex;
            Iterator(Board* board, size_t currIndex);

            public:
                bool operator!=(const Iterator& other);
                Iterator& operator++();
        };

        // Board(bool setup);
        virtual ~Board() = 0;
        virtual char pieceAt(int , int ) = 0;
        // bool validBoard();
        // bool validMove();
        Iterator begin() const;
        Iterator end() const;
};


#endif
