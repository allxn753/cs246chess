#include "helpers.h"

using namespace std;

vector<int> convertPosition(string pos) {
    int y = char(pos[1] - '1');
    int x = int(pos[0]) - 'a';    
    vector<int> v = {x,y};
    return v;
}
