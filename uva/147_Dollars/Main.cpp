/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  4217 147  C++  "DP Coin Change" */
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
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }
typedef pair<int,int> ii;
typedef vector<ii> vii;

#define N 30001
unsigned long long M[N];
int C[] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};

int main() {
    M[0] = 1;
    float x;
    for(int i = 0; i < 11; ++i) {
        for(int j = C[i]; j < N; ++j) {
            M[j] += M[j-C[i]];
        }
    }
    while(scanf("%f",&x) == 1) {
        int n = round(x*100.0);
        if ( n == 0 ) break;
        printf("%6.2f%17llu\n",x,M[n]);
    }
    return 0;
}
/* @END_OF_SOURCE_CODE */
