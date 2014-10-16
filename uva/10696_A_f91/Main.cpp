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

int f91(int N) {
     if (N <= 100) return f91(f91(N+11));
     return N-10;
}

int main() {
    int a;
    while(scanf("%d\n",&a)==1) {
        if (a==0) break;
        printf("f91(%d) = %d\n",a,f91(a));
    }
	return 0;
}
/* @END_OF_SOURCE_CODE */
