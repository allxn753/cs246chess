#include "board.h"

void Board::display() { notifyObservers(); }

void Board::addPiece(char type, string pos) {
    vector<int> coord = convertPosition(pos);
    char p = tolower(type);

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
    vector<int> coord = convertPosition(pos);
    delete pieces->pieceAt(coord[0], coord[1]);
}

Piece* Board::getPiece(int x, int y) const {
    return pieces->pieceAt(x, y);
}

char Board::getChar(int x, int y) const {
    return pieces->pieceAt(x, y)->getChar();
}

void Board::print(string pos) {
    vector<int> coord = convertPosition(pos);
    std::cout << pieces->pieceAt(coord[0], coord[1])->getChar() << std::endl << std::endl;
}

Board::~Board(){ delete pieces; }
