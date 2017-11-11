/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int freq[256];

char lower(char ch) {
    if (ch >= 'A' && ch <= 'Z')
        return (ch - 'A') + 'a';
    return ch;
}

int main() {

    string s;
    getline(cin, s);

    for(int i = 0; i < 256; ++i)
        freq[i] = 0;
    
    for(int i = 0; i < s.size(); ++i) {
        char ch = lower(s[i]);
        freq[ch]++;
    }

    bool res = true;
    for(char ch = 'a'; ch <= 'z'; ++ch) {
        if(!freq[ch]) {
            res = false;
            break;
        }
    }

    cout << (res ? "pangram": "not pangram") << '\n';
    
    return 0;
}
