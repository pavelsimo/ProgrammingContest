/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  4217 10783  C++  "Ad Hoc" */
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
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
    int tc, a, b;
    int k = 0;
    while (scanf("%d",&tc) == 1 ) {
        for(int c = 1; c <= tc; ++c) {
            int res = 0;
            scanf("%d",&a);
            scanf("%d",&b);
            int from = min(a,b);
            int to = max(a,b);
            if ( from % 2 == 0 ) from++;
            if ( to % 2 == 0 ) to--;
            for(int i = from; i <= to; i+=2) 
                res+=i;
            k++;
            printf("Case %d: %d\n",k,res);
        }
    }
	return 0;
}
/* @END_OF_SOURCE_CODE */
