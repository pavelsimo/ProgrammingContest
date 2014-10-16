/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  639  C++  "Backtracking" */
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
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)

int n;
int INF = 1000000;
const int maxn = 4;
char C[maxn][maxn];
int memo[maxn][maxn][1<<maxn][1<<maxn];

int d(int i, int j, int col, int row) {
	if(i==n) return 0;
	if(j==n) return d(i+1,0,col,row);
	if(memo[i][j][col][row] != -1) return memo[i][j][col][row];
	int ans = 0;
	if(C[i][j]=='X') {
		ans = d(i,j+1,col&(15-(1<<i)),row&(15-(1<<j)));
	} else {
		if((col&(1<<i))==0 && (row&(1<<j))==0) {
			ans= max(d(i,j+1,col,row),d(i,j+1,col|(1<<i),row|(1<<j))+1);
		} else {
			ans = d(i,j+1,col,row);
		}
	}
	return memo[i][j][col][row] = ans;
}

int main() {
   int ans;
	while(scanf("%d",&n)==1) {
		memset(memo,-1,sizeof(memo));
		if(n==0) break;
		for(int i = 0; i < n; ++i)
			scanf("%s",C[i]);
		ans = d(0,0,0,0);
		printf("%d\n",ans);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
