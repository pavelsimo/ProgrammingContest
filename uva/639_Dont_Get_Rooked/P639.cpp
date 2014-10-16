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


const int maxn = 4;
const int dir = 4;
int cnt, ans, n;
char C[maxn+1][maxn+1];
int vis[maxn+1][maxn+1];
int dx[] = {+1,-1,+0,0};
int dy[] = {+0,+0,-1,+1};

int valid(int x, int y) {
	if(vis[x][y] || C[x][y] == 'X') return 0;
	for(int d = 0; d < dir; ++d) {
		int nx = x;
		int ny = y;
		for(int i = 0; i < n; ++i) {
			nx +=dx[d];
			ny +=dy[d];
			if(nx >= n || ny >= n || nx < 0 || ny < 0 || C[nx][ny] == 'X') break;
			if(vis[nx][ny]) return 0;					
		}
	}
	return 1;
}

void dfs(int cur) {
	if(cur==n) {
		cnt=0;
		REP(i,n) {
			REP(j,n) {
				if(vis[i][j]) {
					cnt++;
				} else {
					if(C[i][j]=='.' && valid(i,j)) {
						cnt++; vis[i][j]=1;
					}
				}
			}
		}
		if(cnt>ans) ans=cnt;
	} else {
		for(int i = 0; i < n; ++i) {
			if(valid(cur,i)) {
				vis[cur][i] = 1;
				dfs(cur+1);
				vis[cur][i] = 0;
			} else {
				dfs(cur+1);
			}
		}	
	}
}

int main() {
	while(scanf("%d",&n)==1) {
		if(n==0) break;
		ans=0;
		memset(vis,0,sizeof(vis));
		for(int i = 0; i < n; ++i)
			scanf("%s",C[i]);
		dfs(0);
		printf("%d\n",ans);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
