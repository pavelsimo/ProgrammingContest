/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  15240 100  C++  "Simple Algorithm" */
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
typedef vector<int> VI;
typedef vector<string> VS;
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

int main() {
    int a;
    int b; 
    while ( cin >> a >> b ) {
        int max = -1;
        int begin;
        int end;
        if ( a < b ) {
            begin = a;
            end = b;
        } else {
            begin = b;
            end = a;
        }
        for(int i = begin; i <= end; ++i) {
            int n = i;
            int cnt = 1;
            while ( n > 1 ) {
                if ( n % 2 == 1 )
                    n = 3*n + 1;
                else
                    n >>= 1;
                cnt++;
            }
            if ( cnt > max )
                max = cnt;
        }
        printf("%d %d %d\n", a,b,max);
    }

    return 0;
}
/* @END_OF_SOURCE_CODE */
