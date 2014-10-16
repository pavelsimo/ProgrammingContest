/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  4217 10066  C++  "DP LCS" */
#include <cstring>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <cmath>
#include <complex>
#include <stack>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)
typedef vector<int> VI;
typedef vector<string> VS;
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

#define N 101

int a[N];
int b[N];
int C[N][N];

int LCS(int n, int m) {
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if ( a[i-1] == b[j-1] ) {
                C[i][j] = C[i-1][j-1] + 1;
            } else {
                C[i][j] = max(C[i-1][j],C[i][j-1]);
            }
        }
    }
    return C[n][m];
}

int main() {
    int n, m;
    int tc = 0;
    while(scanf("%d %d",&n,&m)) {
        if (n==0 && m==0) break;
        memset(C, 0,sizeof(C));
        for(int i = 0; i < n; ++i) scanf("%d",&a[i]);
        for(int i = 0; i < m; ++i) scanf("%d",&b[i]);
        printf("Twin Towers #%d\n",++tc);
        printf("Number of Tiles : %d\n\n",LCS(n,m));
    }
    return 0;
}
/* @END_OF_SOURCE_CODE */
