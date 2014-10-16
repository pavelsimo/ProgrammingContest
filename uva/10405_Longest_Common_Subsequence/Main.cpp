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

int C[1001][1001];

int LCS(string x, string y) {
    int n = x.size();
    int m = y.size();
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if ( x[i-1] == y[j-1] ) {
                C[i][j] = C[i-1][j-1] + 1;
            } else {
                C[i][j] = max(C[i-1][j],C[i][j-1]);
            }
        }
    }
    return C[n][m];
}

int main() {
    string s[2];
    int k = 0;
    while (getline(cin,s[k])) {
        k++;
        if ( k == 2 ) {
            memset(C,0,sizeof(C));
            k = 0;
            printf("%d\n",LCS(s[0],s[1]));
        }
    }
	return 0;
}
/* @END_OF_SOURCE_CODE */
