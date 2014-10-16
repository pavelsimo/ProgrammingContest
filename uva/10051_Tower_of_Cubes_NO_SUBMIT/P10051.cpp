/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10051  C++  "Dynamic Programming, LIS" */
#include <iostream>
#include <cstring> 
#include <algorithm>
#include <numeric>
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
#include <bitset>
#include <utility>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)

const int maxn = 510;
const int nside = 6;

// front, back, left, right, top, bottom
int cube[maxn][nside];
int L[maxn];
int W[maxn];
int C[maxn];

int lis(int n) {
	int ans = 0;
	for(int i = 0; i <= n; ++i) L[i] = 1;
	for(int j = 2; j <= n; ++j) {
		
		for(int i = j-1; i >= 1; --i) {
			if(W[i] < W[j]) {
				
				
				L[j] = max(L[j],L[i]+1);
			}
		}
		
		ans = max(ans,L[j]);
	}
	return ans;
}

int main() {
	int n;
	while(scanf("%d",&n)==1) {
		for(int i = 1; i <= n; ++i) {
			W[i] = i;
			for(int j = 0; j < nside; ++j) {
				scanf("%d",&cube[i][j]);
			}
		}
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
