/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

#include <bits/stdc++.h>
#include <cstring>

using namespace std;

typedef long long llong;

const int MAXN = 252;
const int MAXM = 52;
llong memo[MAXN][MAXM];
int n, m;
int c[MAXM];

llong go(int cur, int k) {
    if (cur == 0)
        return 1LL;    
    if (k >= m)
        return 0LL;
    if (memo[cur][k] != -1)
        return memo[cur][k];
    llong res = 0LL;    
    if (cur - c[k] >= 0) {
        res += go(cur - c[k], k);        
    }
    res += go(cur, k + 1);
    memo[cur][k] = res;
    return res;
}

int main() {
    memset(memo, -1, sizeof(memo));
    
    cin >> n >> m;
    for(int i = 0; i < m; i++){
       cin >> c[i];       
    }

    cout << go(n, 0) << endl;
    
    return 0;
}
