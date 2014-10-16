/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  4217 167  C++  "Backtracking 8 Queens" */
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

#define N 8
int D[N+1][N+1];
int x[N+1];
int best;

int ok(int k) {
    for(int i = 1; i < k; ++i) {
        if ( x[i] == x[k] || abs(x[i]-x[k]) == k-i )
            return 0;
    }
    return 1;
}

int cost(int k) {
    int res = 0;
    for(int i = 1; i <= k; ++i)
        res+=D[i][x[i]];
    return res;
}

void back(int k) {
    if ( k == N ) {
        best = max(best,cost(k));
    } else {
        for(x[k+1] = 1; x[k+1] <= N; ++x[k+1]) {
            if ( ok(k+1) ) {
                back(k+1);
            }
        }
    }
}

int main() {
    int ncases;
    scanf("%d",&ncases);
    while ( ncases-- > 0 ) {
        best = 0;
        for(int i = 1; i <= N; ++i) {
            for(int j = 1; j <= N; ++j) {
                scanf("%d",&D[i][j]);
            }
        }
        back(0);
        printf("%5d\n",best);
    }
    return 0;
}
/* @END_OF_SOURCE_CODE */
