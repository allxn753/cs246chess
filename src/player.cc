#include "player.h"

Player::Player(string playerColour, Game* game) : playerColour{playerColour}, game{game} {}

Board* Player::getBoard() {
    return game->getBoard();
}
