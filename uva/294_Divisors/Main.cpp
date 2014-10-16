/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  15240 294  C++  "Number Theory" */
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

int div(int n) {
    int res = 0, k;
    for (k = 1; k * k < n; ++k)
        if (n % k == 0) res += 2;
    if (k*k == n)
       res++;
    return res;
}

int main() {
    int k;
    int a, b;
    char buf[128];
    scanf("%d\n",&k);
    for(int i = 0; i < k; ++i) {
        gets(buf);
        sscanf(buf,"%d %d",&a,&b);
        int maxDiv = 0;
        int maxNumber = 0;
        for(int j = a; j <= b; ++j) {
            int t = div(j);
            if ( t > maxDiv ) {
               maxDiv = t;
               maxNumber = j;
            } 
        }
        printf("Between %d and %d, %d has a maximum of %d divisors.\n",a,b,maxNumber,maxDiv);
    }
    
    return 0;
}
/* @END_OF_SOURCE_CODE */
