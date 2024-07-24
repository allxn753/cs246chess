#include "game.h"
#include <vector>

Game::Game(Board* brd): theBoard{brd}{}

bool Game::validMove(string pos1, string pos2) {
    // vector<int> coord1 = convertPosition(pos1);
    // vector<int> coord2 = convertPosition(pos2);

    // char activePiece = theBoard->getPiece(coord1[0], coord1[1])->getChar();

    // if ()

    // switch (tolower(activePiece)) {
    //     case ' ': return false;
    //     case '_': return false;
    //     case 'k':
    // }
}

bool Game::isThreatened(string pos) {

}
