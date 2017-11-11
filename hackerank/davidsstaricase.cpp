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
int N;    

int go(int x) {
    if (x > N) return 0;
    if (x == N) return 1;
    if (memo[x] != -1) return memo[x];
    memo[x] = go(x + 1) + go(x + 2) + go(x + 3);
    return memo[x];
}

int main(){
    int s;
    cin >> s;
    for(int i = 0; i < s; ++i) {
        memset(memo, -1, sizeof(memo));        
        cin >> N;
        cout << go(0) << endl;
    }
    return 0;
}
