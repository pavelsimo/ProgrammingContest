/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  4217 481  C++  "DP Longest Increasing Subsequence" */
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

int a[100000];
int v[100000];
int best[100000];
int prev[100000];

int main() {
    int x, i=0, m=0, k=0;
    for(int i = 0; scanf("%d",&x) == 1; ++i) {
        a[i]=x;
        best[i]=1;
        prev[i]=i;
        for(int j = 0; j < i; ++j) {
            if ( a[i] > a[j] && best[i] < best[j] + 1) {
                best[i] = best[j] + 1;
                prev[i] = j;
                if ( m <= best[i] ) {
                    m = best[i];
                    k = i;
                }
            }
        }
    }
    for(int i = 0; i < m; ++i) {
        v[i]=a[k];
        k = prev[k];
    }
    printf("%d\n-\n",m);
    for(int i = m-1; i >= 0; --i)   
        printf("%d\n",v[i]);
	return 0;
}
/* @END_OF_SOURCE_CODE */
