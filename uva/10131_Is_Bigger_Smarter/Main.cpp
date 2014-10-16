/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  4217 10131  C++  "DP Longest Increasing Subsequence" */
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
//#define DEBUG
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }
typedef pair<int,int> ii;
typedef vector<ii> vii;

struct node {
  int w;
  int iq;
  int index;
  node(int nw, int niq, int nindex) {
    w = nw;
    iq = niq; 
    index = nindex;
  }
};

bool operator<(const node &a, const node &b) {
  if ( a.w != b.w  ) 
    return b.w > a.w;
  if ( a.iq != b.iq ) 
    return b.iq < a.iq;
  return false;
}

vector<node> a;
int best[1002];
int prev[1002];
int w, iq;

int main() {
    vector<int> v;
    int n = 0;
    while ( scanf("%d %d",&w,&iq) == 2 ) {
        a.push_back(node(w, iq,++n));
    }
    sort (a.begin(), a.end());
    for(int i = 0; i < n; ++i) {
        best[i] = 1;
        prev[i] = i;
    }
    for(int i = 1; i < n; ++i) {
        for(int j = 0; j < i; ++j) {
            if ( a[i].w > a[j].w && a[i].iq < a[j].iq 
                    && best[i] < best[j] + 1 ) {
                best[i] = best[j] + 1;
                prev[i] = j;
            }
        }
    }
    int M = 0;
    int k = 0;
    for(int i = 0; i < n; ++i) {
        if ( M <= best[i] ) {
            M = best[i];
            k = i;
        }
    }
    // backtracking
    for(int i = 0; i < M; ++i) {
        v.push_back(a[k].index);
        k = prev[k];
    }
    printf("%d\n",M);
    for(int i = M-1; i >= 0; --i)
        printf("%d\n",v[i]);
	return 0;
}
/* @END_OF_SOURCE_CODE */
