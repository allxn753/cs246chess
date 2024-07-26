#include "helpers.h"

using namespace std;

vector<int> convertPosition(string pos) {    
    int x = int(pos[0]) - 'a';    
    int y = int(pos[1] - '1');
    vector<int> v = {x,y};
    return v;
}

string convertPosition(int x, int y) {
    string s;
    s += char('a' + x);
    s += char('1' + y);
    return s;

}
