/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ 408  C++  "DP " */
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
    int tc, n, x;
    scanf("%d",&tc);
    for(int c = 1; c <= tc; ++c) {
        scanf("%d",&n);
        int best = -1,sum=0,start=1,end=1,k=1, d=0, t=1;
        for(int i = 1; i < n; ++i) {
            scanf("%d",&x);
            sum+=x;
            if ( sum > best || (sum == best && i-t > d) ) {
                best = sum;
                start = k;
                t = start;
                end = i+1;
                d = end-start-1;
            } else if ( sum < 0 ) {
                sum = 0;
                k = i+1;
                t = k;
            }
        }
        if ( best == -1 ) 
            printf("Route %d has no nice parts\n",c);
        else
            printf("The nicest part of route %d is between stops %d and %d\n",c,start,end);
    }
	return 0;
}
/* @END_OF_SOURCE_CODE */
