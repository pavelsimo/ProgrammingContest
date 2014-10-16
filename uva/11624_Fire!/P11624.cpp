/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11624  C++  "Graph Theory, BFS" */
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)

typedef pair<int,int> ii;
typedef vector<ii> vii;
const int maxn = 1024;
const int maxd = 4;
int D[maxn][maxn];
int F[maxn][maxn];
char B[maxn][maxn];
char buf[maxn];
int dx[] = {+1,-1,+0,+0};
int dy[] = {+0,+0,+1,-1};
int n, m;
vii p;

void firebfs() {
	queue<ii> Q;
	for(int i = 0; i < p.size(); ++i) {
		Q.push(p[i]);
		F[p[i].first][p[i].second]=0;
	}
	while(!Q.empty()) {
		ii cur = Q.front(); Q.pop();
		int x = cur.first;
		int y = cur.second;
		for(int d = 0; d < maxd; ++d) {
			int nx=x+dx[d];
			int ny=y+dy[d];
			if(nx < 0 || ny < 0 || nx >= n || ny >= m || B[nx][ny]=='#' || F[nx][ny]>=0) continue;
			F[nx][ny]=F[x][y]+1;
			Q.push(ii(nx,ny));
		}
	}
}

int bfs(int sx, int sy) {
	queue<ii> Q;
	Q.push(ii(sx,sy));
	D[sx][sy]=0;
	while(!Q.empty()) {
		ii cur = Q.front(); Q.pop();
		int x=cur.first;
		int y=cur.second;
		if(F[x][y]!=-1 && D[x][y] >= F[x][y]) continue;
		for(int d = 0; d < maxd; ++d) {
			int nx=x+dx[d];
			int ny=y+dy[d];
			if(nx<0 || nx>=n || ny<0 || ny>=m) return D[x][y]+1;
			if(D[nx][ny]==-1 && B[nx][ny]=='.') {
				D[nx][ny]=D[x][y]+1;
				Q.push(ii(nx,ny));			
			}
		}
	}
	return -1;
}

int main(int argc, char *argv[]) {
	int TC, sx, sy, ans;
	gets(buf);
	sscanf(buf,"%d",&TC);
	while(TC-- > 0) { 
		p.clear();
		memset(F,-1,sizeof(F));
		memset(D,-1,sizeof(D));
		gets(buf);
		sscanf(buf,"%d%d",&n,&m);
		for(int i = 0; i < n; ++i)
			gets(B[i]);
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				if(B[i][j]=='J') {
					sx=i;
					sy=j;
				} else if(B[i][j]=='F') {
					p.push_back(ii(i,j));
				}
			}
		}
		firebfs();
		ans=bfs(sx,sy);
		if(ans>=0) printf("%d\n",ans);
		else printf("IMPOSSIBLE\n");
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

