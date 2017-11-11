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

const int MAXN = 64;
int memo[MAXN];

int go(int n) {
    if (n < 0) return 0;
    if (n == 0) return 1;
    if (memo[n] != -1) return memo[n];
    memo[n] = go(n - 1) + go(n - 2) + go(n - 3);
    return memo[n];
}

int main(){
    int n, s;
    cin >> s;
    memset(memo, -1, sizeof(memo));            
    for(int i = 0; i < s; ++i) {
        cin >> n;
        cout << go(n) << endl;
    }
    return 0;
}
