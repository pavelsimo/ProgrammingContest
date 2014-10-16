/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  4217 231  C++  "DP Longest Increasing Subsequence" */
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

int best[327680];
int a[327680];

int main() {
    int x, n = 0;
    int tc = 1;
    while(scanf("%d",&x) == 1) {
        if ( x > 0 ) {
            a[n] = x;
            n++;
        } else {
            if ( n == 0 ) continue;
            if ( tc != 1 ) printf("\n");
            int res = 0;
            for(int i = 0; i < n; ++i) 
                best[i] = 1;
            for(int i = 1; i < n; ++i) {
                for(int j = 0; j < i; ++j) {
                    if ( (a[j] > a[i] || a[j] == a[i]) && best[i] < best[j] + 1) {
                        best[i] = best[j] + 1;
                    }
                }
            }
            for(int i = 0; i < n; ++i) 
                res = max(res,best[i]);
            printf("Test #%d:\n",tc);
            printf("  maximum possible interceptions: %d\n",res);
            tc++;
            n = 0;  
        }
    }
	return 0;
}
/* @END_OF_SOURCE_CODE */
