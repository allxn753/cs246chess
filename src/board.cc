#include "board.h"

vector<int> convertPosition(string pos) {
    int x = int(pos[1] - '1' + 1);
    int y = char(pos[0]) - 'a' + 1;
    vector<int> v = {x,y};
    return v;
}

void Board::display() { notifyObservers(); }

void Board::addPiece(char type, string pos) {
    vector<int> coord = convertPosition(pos);
    char p = char(tolower(type));

    switch(p){
        case 'r': pieces = new Rook(pieces, coord[0], coord[1], 5, isupper(type) ? "black" : "white"); break;
        case 'n': pieces = new Knight(pieces, coord[0], coord[1], 3, isupper(type) ? "black" : "white"); break;
        case 'b': pieces = new Bishop(pieces, coord[0], coord[1], 3, isupper(type) ? "black" : "white"); break;
        case 'q': pieces = new Queen(pieces, coord[0], coord[1], 9, isupper(type) ? "black" : "white"); break;
        case 'k': pieces = new King(pieces, coord[0], coord[1], 100, isupper(type) ? "black" : "white"); break;
        case 'p': pieces = new Pawn(pieces, coord[0], coord[1], 1, isupper(type) ? "black" : "white"); break;
    }
    
}

void Board::removePiece(string pos) {

}

Piece* Board::getPiece(int x, int y) const {
    return pieces->pieceAt(x, y);
}

Board::~Board(){ delete pieces; }
