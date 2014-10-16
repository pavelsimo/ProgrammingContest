/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  4217 674  C++  "DP Coin Change" */
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

#define N 7500
int M[N+1];
int C[] = {1,5,10,25,50};

int main() {
    int x;
    M[0] = 1;
    for(int i = 0; i < 5; ++i) {
        for(int j = C[i]; j <= N; ++j) {
            M[j] += M[j-C[i]];
        } 
    }   
    while(scanf("%d",&x) == 1) {
        printf("%d\n",M[x]);
    }
    return 0;
}
/* @END_OF_SOURCE_CODE */
