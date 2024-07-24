#include "helpers.h"

using namespace std;

vector<int> convertPosition(string pos) {
    int x = int(pos[0]) - 'a';
    int y = char(pos[1] - '1');
    vector<int> v = {x,y};
    return v;
}
