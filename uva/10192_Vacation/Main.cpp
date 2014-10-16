/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  4217 10405  C++  "DP LCS" */
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
#define DEBUG
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }
typedef pair<int,int> ii;
typedef vector<ii> vii;

int DP[102][102];

int LCS(string x, string y) {
    int n = x.size();
    int m = y.size();
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if ( x[i-1] == y[j-1] ) {
                DP[i][j] = DP[i-1][j-1] + 1;
            } else {
                DP[i][j] = max(DP[i-1][j],DP[i][j-1]);
            }
        }
    }
    return DP[n][m];
}

int main() {
    string s[2];
    int i = 0;
    int tc = 0;
    while ( getline(cin,s[i]) ) {
        if ( s[i] == "#" ) break;
        i++;
        if ( i == 2 ) {
            memset(DP,0,sizeof(DP));
            printf("Case #%d: you can visit at most %d cities.\n",++tc,LCS(s[0],s[1]));
            i = 0;
        }
    }
	return 0;
}
/* @END_OF_SOURCE_CODE */
