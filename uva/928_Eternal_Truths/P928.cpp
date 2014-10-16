/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  928  C++  "Graph Theory, BFS" */
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
	int jump;
	int cost;
	node(int _x, int _y, int _jump, int _cost) {
		x=_x;
		y=_y;
		jump=_jump;
		cost=_cost;
	}
};

const int maxn=310;
char board[maxn][maxn];
bool vis[maxn][maxn][4];
int ndir = 4;
int dx[] = {+1,+0,-1,+0};
int dy[] = {+0,+1,+0,-1};
int n, m;

int bfs(int sx, int sy, int tx, int ty) {
	queue<node> Q;
	Q.push(node(sx,sy,1,0));
	vis[sx][sy][1]=true;
	while(!Q.empty()) {
		node cur = Q.front(); Q.pop();
		if(cur.x==tx && cur.y==ty) return cur.cost;
		int next = cur.jump+1 > 3 ? 1: cur.jump+1;
		for(int d = 0; d < ndir; ++d) {
			int nx = cur.x;
			int ny = cur.y;
			bool ok = true;
			for(int k = 0; k < cur.jump; ++k) {
				nx+=dx[d];
				ny+=dy[d];
				if(nx < 0 || ny < 0 || nx >= n || ny >= m || board[nx][ny]=='#') {
					ok=false;
					break;
				}
			}
			if(!vis[nx][ny][next] && ok) {
				vis[nx][ny][next]=true;
				Q.push(node(nx,ny,next,cur.cost+1));
			}
		}
	}
	return -1;
}

int main(int argc, char *argv[]) {
	int TC, sx, sy, tx, ty, ans;
	scanf("%d",&TC);
	while(TC-- > 0) {
		scanf("%d%d",&n,&m);
		memset(vis,false,sizeof(vis));
		for(int i = 0; i < n; ++i) {
			scanf("%s",&board[i]);
			for(int j = 0; j < m; ++j) {           
				if(board[i][j]=='S') {
					sx=i;
					sy=j;
				} else if(board[i][j]=='E') {
					tx=i;
					ty=j;
				}
			}
		}
		ans=bfs(sx,sy,tx,ty);
		if(ans>=0) printf("%d\n",ans);
		else puts("NO");
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

