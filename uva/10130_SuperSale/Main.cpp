/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  15240 10130  C++  "DP Knapsack 0-1" */
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
//#define DEBUG
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }
typedef pair<int,int> ii;
typedef vector<ii> vii;
int DP[1002][31];
int b[1002];
int w[1002];
int p[102];

int main() {
    int ncases, n, m;
    scanf("%d",&ncases);
    while (ncases-- > 0) {
        memset(DP,0,sizeof(DP));
        memset(p,0,sizeof(p));
        memset(b,0,sizeof(b));
        memset(w,0,sizeof(w));
        scanf("%d",&n);
        for(int i = 1; i <= n; ++i)
            scanf("%d %d",&b[i],&w[i]);
        scanf("%d",&m);
        for(int i = 0; i < m; ++i)
            scanf("%d",&p[i]);
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= 30; ++j) {
                if ( w[i] <= j ) {
                    DP[i][j] = max(DP[i-1][j],DP[i-1][j-w[i]] + b[i]);
                } else {
                    DP[i][j] = DP[i-1][j];
                }
            }
        }
        int res = 0;
        for(int i = 0; i < m; ++i)
            res+= DP[n][p[i]];
        printf("%d\n",res);
    }
    return 0;
}
/* @END_OF_SOURCE_CODE */
