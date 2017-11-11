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


const int NCHARS = 26;
set<int> u[NCHARS];

int main() {
    
    string s;
    cin >> s;

    for(int i = 0; i < NCHARS; ++i) {
        int cnt = 0;
        for(int k = 0; k < s.size(); ++k) {
            char ch = 'a' + i;            
            if(s[k] == ch) {
                cnt += (s[k] - 'a' + 1);
                u[i].insert(cnt);
            } else {
                cnt = 0;
            }
        }
    }    
            
    int n;
    cin >> n;        
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        bool found = false;
        for(int j = 0; j < NCHARS; ++j) {
            if (u[j].count(x) != 0) {
                found = true;
                break;
            }

        }
        cout << (found ? "Yes" : "No") << '\n';        
    }    
    
    return 0;
}
