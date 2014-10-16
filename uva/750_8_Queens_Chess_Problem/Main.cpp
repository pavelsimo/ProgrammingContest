/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  4217 750  C++  "Backtracking 8 Queens" */
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

#define N 8
int x[9];
int cx=0,cy=0;
int tc = 0;

void print(int k) {
    printf("%2d",(++tc));
    for(int i = 1; i <= k; ++i) {
        if ( i == 1 )
            printf("%7d",x[i]);
        else
            printf("%d",x[i]);
        if ( i != k ) 
            printf(" ");
    }
    printf("\n");
}

int ok(int k) {
    for(int i = 1; i < k; ++i) 
        if ( x[i] == x[k] || abs(x[i]-x[k]) == k-i)
            return 0;
    return 1;
}

void back(int k) {
    if ( k == N ) {
        if ( x[cy] == cx ) print(k);
    } else {
        for(x[k+1] = 1; x[k+1] <= N; x[k+1]++) {
            if ( ok(k+1) )
                back(k+1);
        }
    }
}

int main() {
    int ncases;
    scanf("%d\n",&ncases);
    for(int i = 0; i < ncases; ++i) {
    printf("SOLN       COLUMN\n");
    printf(" #      1 2 3 4 5 6 7 8\n");
        tc = 0;
        printf("\n");
        scanf("%d %d",&cx,&cy);
        back(0);
        if ( i != ncases-1 )        
            printf("\n");
    }
    return 0;
}
/* @END_OF_SOURCE_CODE */
