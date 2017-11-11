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

int main() {
    int n;
    cin >> n;
    int x;
    vector<int> p(n + 1);
    for(int i = 1; i <= n; ++i) {
        cin >> p[i];
    }
    for(int x = 1; x <= n; ++x) {
        int y = 1;
        for(; y < n; ++y) {
            if (x == p[p[y]]) {
                break;
            }
        }        
        cout << y << endl;
    }    
    return 0;
}
