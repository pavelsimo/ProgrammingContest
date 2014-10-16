/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10229  C++  "..." */
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


long long fib(long long n, long long m) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return (fib(n-2,m)%m+fib(n-1,m)%m)%m;
}


long long fib2(long long n, long long m) {
    long long a = 0;
    long long b = 1;
    long long res = 1;
    for(int i = 1; i < n; ++i) {
        res = (a+b)%m;
        a = b;
        b = res;
    }
    return res%m;
}


int main() {
    int n,m;
    while ( scanf("%d %d",&n,&m) == 2 ) {
        long long x = n;
        long long exp = 1 << m;
        cout << fib2(x,exp) << endl;
    }
    return 0;
}
/* @END_OF_SOURCE_CODE */
