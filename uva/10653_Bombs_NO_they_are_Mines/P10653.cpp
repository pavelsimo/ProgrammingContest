/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10653  C++  "Graph Theory, BFS" */
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

struct node {
	int x;
	int y;
	int d;
	node(int _x, int _y, int _d) {
		x=_x;
		y=_y;
		d=_d;
	}
};

const int maxn = 1002;
bool vis[maxn][maxn];
int dx[] = {+1,-1,+0,+0};
int dy[] = {+0,+0,+1,-1};
int R, C, ndir=4;

int bfs(int sx, int sy, int tx, int ty) {
	queue<node> Q;
	Q.push(node(sx,sy,0));
	vis[sx][sy] = true;
	while(!Q.empty()) {
		node cur = Q.front(); Q.pop();
		if(cur.x==tx && cur.y == ty) return cur.d;
		for(int d = 0; d < ndir; ++d) {
			int nx = cur.x + dx[d];
			int ny = cur.y + dy[d];
			if(nx < 0 || ny < 0 || nx >= R || ny >= C || vis[nx][ny]) continue;
			Q.push(node(nx,ny,cur.d+1));
			vis[nx][ny] = true;
		}
	}
	return -1;
}

int main(int argc, char *argv[]) {
	int ans, n, m, v, u, sx, sy, tx, ty;
	while(scanf("%d%d",&R,&C)==2) {
		if(R==0 || C==0) break;
		memset(vis,false,sizeof(vis));
		scanf("%d",&n);
		for(int i = 1; i <= n; ++i) {
			scanf("%d%d",&v,&m);
			while(m-- > 0) {
				scanf("%d",&u);
				vis[v][u] = true;
			}
		}
		scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
		ans=bfs(sx,sy,tx,ty);
		if(ans>=0) printf("%d\n",ans);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

