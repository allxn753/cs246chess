#include "board.h"
#include "helpers.h"
#include "blank.h"

void Board::display() { notifyObservers(); }

void Board::addPiece(char type, string pos) {
    vector<int> coord = convertPosition(pos);
    Decorator * d;
    char p = tolower(type);
    switch(p) {
        case 'r': d = new Rook(pieces, coord[0], coord[1], 5, islower(type) ? "black" : "white"); break;
        case 'n': d = new Knight(pieces, coord[0], coord[1], 3, islower(type) ? "black" : "white"); break;
        case 'b': d = new Bishop(pieces, coord[0], coord[1], 3, islower(type) ? "black" : "white"); break;
        case 'q': d = new Queen(pieces, coord[0], coord[1], 9, islower(type) ? "black" : "white"); break;
        case 'k': d = new King(pieces, coord[0], coord[1], 100, islower(type) ? "black" : "white"); break;
        case 'p': d = new Pawn(pieces, coord[0], coord[1], 1, islower(type) ? "black" : "white"); break;
    }
    arr.emplace_back(d);
    pieces = d;
    ++numPieces;
}

void Board::removePiece(string pos) {
    vector<int> coord = convertPosition(pos);
    Piece* p = pieces->pieceAt(coord[0], coord[1]);
    if (p->getChar() == ' ' || p->getChar() == '_') {
        return;
    } else { // piece on tile
        for(int i = 0; i < numPieces; ++i) {
            if (arr[i]->getX() == coord[0] && arr[i]->getY() == coord[1]) { // found piece.              
                if(i != numPieces - 1) arr[i + 1]->piece = arr[i]->piece; // not last element
                else pieces = arr[i]->piece; // last element (including 1 item list)
                arr[i]->piece = nullptr;                
                delete arr[i];                    
                arr.erase(arr.begin() + i);
                --numPieces;
                break;           
            } // found piece
        } // for
    } // piece on tile  
    // delete pieces->pieceAt(coord[0], coord[1]);
}

Piece* Board::getPiece(int x, int y) {
    return pieces->pieceAt(x, y);
}

Piece* Board::getPiece(string pos) {
    vector<int> coord = convertPosition(pos);
    return pieces->pieceAt(coord[0], coord[1]);
}

vector<Decorator*> Board::getArr() {
    return arr;
}

int Board::getNumPieces() {
    return numPieces;
}

char Board::getChar(int x, int y) const {
    return pieces->pieceAt(x, y)->getChar();
}

void Board::print(string pos) {
    vector<int> coord = convertPosition(pos);
    std::cout << pieces->pieceAt(coord[0], coord[1])->getChar() << std::endl << std::endl;
}

Board::~Board(){ delete pieces; }

void Board::wipe() {
    delete pieces;
    pieces = new Blank{};
    numPieces = 0;
    arr.clear();
}