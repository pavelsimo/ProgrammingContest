/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11461  C++  "Simple Math" */
#include <cstdio>
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

int main() {
    int a,b;
    while (scanf("%d %d",&a,&b) == 2 ) {
        if ( a == 0 && b == 0 ) break;
        int n = (int)sqrt(b);
        int res = 0;
        for(int i = 1; i <= n; ++i)
            if ( i*i >= a && i*i <= b) 
                res++;
        printf("%d\n",res);
    } 
	return 0;
}
/* @END_OF_SOURCE_CODE */
