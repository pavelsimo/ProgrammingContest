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

int n, m;
int a[32][32];
int seen[32][32];

int di[] = {-1, -1, -1, +0, +0, +1, +1, +1};
int dj[] = {-1, +0, +1, -1, +1, -1, +0, +1};

int dfs(int i, int j) {
    int res = 1;
    
    if (i < 0 || i >= n || j < 0 || j >= m || a[i][j] == 0)
        return 0;

    if (seen[i][j])
        return 0;
    
    seen[i][j] = 1;
    
    for(int d = 0; d < 8; ++d)
    {
        int ni = i + di[d];
        int nj = j + dj[d];
        res = res + dfs(ni, nj);
    }
        
    return res;
}

int main() {
    cin >> n;
    cin >> m;
    
    for(int i = 0; i < n; ++i){
       for(int j = 0; j < m; ++j){
          cin >> a[i][j];
       }
    }

    int res = 0;
    for(int i = 0; i < n; ++i){
       for(int j = 0; j < m; ++j){
           if(a[i][j] == 1 && !seen[i][j]) {
               res = max(res, dfs(i, j));
           }
       }
    }

    cout << res << endl;
    
    return 0;
}
