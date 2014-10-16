/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  4217 497  C++  "DP Longest Increasing Subsequence" */
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
#define DEBUG
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
    int tc, x, c=0;
    scanf("%d\n",&tc);
    while(c < tc) {
        vector<int> v,a,best,prev;
        int n = 0, m = 0, k = 0;
        char buf[128]; 
        if ( c != 0 ) printf("\n");        
        while(gets(buf)) {
            if ( !isdigit(buf[0]) ) break;
            x = atoi(buf);
            a.push_back(x); 
            n++;
        }
        for(int i = 0; i < n; ++i) {
            best.push_back(1);
            prev.push_back(i);
        }
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if ( a[i] > a[j] && best[i] < best[j] + 1) {
                    best[i] = best[j] + 1;
                    prev[i] = j;
                }
            }
        }
        for(int i = 0; i < n; ++i) {
            if ( m < best[i] ) {
                m = best[i];                
                k = i;
            }
        }
        // backtracking
        for(int i = 0; i < m; ++i) {
            v.push_back(a[k]);
            k = prev[k];
        }
        printf("Max hits: %d\n",m);
        for(int i = m-1; i >= 0; --i) {
            printf("%d\n",v[i]);
        }
        c++;
    }
    
	return 0;
}
/* @END_OF_SOURCE_CODE */
