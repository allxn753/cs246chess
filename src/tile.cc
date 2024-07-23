#include "tile.h"

Tile::Tile(int x, int y) {
    coordinates.push_back(x);
    coordinates.push_back(y);
    piece = nullptr;
}
