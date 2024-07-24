#include "game.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "king.h"
#include "queen.h"
#include <vector>


vector<int> convertPosition(string pos) {
    int x = int(pos[1] - '1' + 1);
    int y = char(pos[0]) - 'a' + 1;
    vector<int> v = {x,y};
    return v;
}


Game::Game(Board* brd): theBoard{brd}{}

void Game::addPiece(char type, string pos) {
    vector<int> coord = convertPosition(pos);
    char p = char(tolower(type));
    switch(p){
        case 'r': theBoard = new Rook(theBoard, type, coord[0], coord[1]) ;break;
        case 'n': theBoard = new Knight(theBoard, type, coord[0], coord[1]) ;break;
        case 'b': theBoard = new Bishop(theBoard, type, coord[0], coord[1]) ;break;
        case 'q': theBoard = new Queen(theBoard, type, coord[0], coord[1]) ;break;
        case 'k': theBoard = new King(theBoard, type, coord[0], coord[1]) ;break;
        case 'p': theBoard = new Pawn(theBoard, type, coord[0], coord[1]) ;break;
    }
}


void Game::display() {
    char curr;
    for (int i = theBoard->HEIGHT; i > 0 ; --i) {
        cout << i << " ";
        for (int j = 1; j <= theBoard->WIDTH; ++j) {
            curr = this->theBoard->pieceAt(i, j);
            if (curr != ' ' || ((i + j) % 2 == 1)) cout << curr;
            else cout << '_';
        }
        cout << endl;
    }
    cout << endl << "  ";
    for (int i = 1; i <= theBoard->WIDTH; ++i) { cout << char('a' + i - 1);}
    cout << endl;
}