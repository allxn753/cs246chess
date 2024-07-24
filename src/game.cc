#include "game.h"
#include <vector>

vector<int> convertPosition(string pos) {
    int x = int(pos[1] - '1' + 1);
    int y = char(pos[0]) - 'a' + 1;
    vector<int> v = {x,y};
    return v;
}

Game::Game(Board* brd): theBoard{brd}{}

bool Game::validMove(string pos1, string pos2) {
    vector<int> coord1 = convertPosition(pos1);
    vector<int> coord2 = convertPosition(pos2);

    char activePiece = theBoard->getPiece(coord1[0], coord1[1])->getChar();

    if ()

    switch (tolower(activePiece)) {
        case ' ': return false;
        case '_': return false;
        case 'k':
    }
}

bool Game::isThreatened(string pos) {

}
