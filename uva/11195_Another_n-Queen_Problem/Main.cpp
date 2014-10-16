/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  4217 11195  C++  "Backtracking" */
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

int x[30];
int v[30];
int n,res;

int ok(int k) {
    if ( x[k] == v[k] ) return 0;
    for(int i = 1; i < k; ++i)
        if ( x[i] == x[k] || abs(x[i]-x[k]) == k-i ) 
            return 0; 
    return 1;
}

void back(int k) {
    if ( k == n ) {
        res++;
    } else {
        for(x[k+1] = 1; x[k+1] <= n; x[k+1]++) {
            if (ok(k+1))
                back(k+1);
        } 
    }
}

int main() {
    char c;
    int tc = 1;
    while (cin >> n) {
        if ( n == 0 ) break;
        res = 0;
        memset(v,0,sizeof(v));
        memset(x,0,sizeof(x));
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
               cin >> c; 
               if ( c == '*' ) v[i] = j;
            }
        }
        back(0);
        printf("Case %d: %d\n",tc,res);
        tc++;
    }
	return 0;
}
/* @END_OF_SOURCE_CODE */
