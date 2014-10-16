/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11049  C++  "Graph Theory, BFS" */
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

typedef pair<int, int> node;
const int maxn=10, nwall=3, ndir=4, n=6, m=6;
char ds[] = {'W','E','N','S'};
int dx[] = {-1,+1,+0,+0};
int dy[] = {+0,+0,-1,+1};
int wall[3][4];
bool vis[maxn][maxn];
node parent[maxn][maxn];
stack<char> path;

int bfs(int sx, int sy, int tx, int ty) {
	queue<node> Q;
	Q.push(make_pair(sx,sy));
	vis[sx][sy] = true;
	while(!Q.empty()) {
		node cur = Q.front(); Q.pop();
		int cx = cur.first;
		int cy = cur.second;
		if(cx==tx && cy==ty) return 1;
		for(int d = 0; d < ndir; ++d) {
			int nx = cx+dx[d];
			int ny = cy+dy[d];
			if(nx < 1 || ny < 1 || nx > 6 || ny > 6 || vis[nx][ny]) continue;
			bool ok = true;
			int x1=cy,y1=cx;
			int x2=cy,y2=cx;
			if(ds[d]=='W'){ y1--; x1--; y2--; } 
			else if(ds[d]=='E') { x1--; 	} 
			else if(ds[d]=='N') { y1--; x1--; x2--; } 
			else if(ds[d]=='S') { y1--; }
			for(int k = 0; k < nwall; ++k) {
				int wx1 = wall[k][0];
				int wy1 = wall[k][1];
				int wx2 = wall[k][2];
				int wy2 = wall[k][3];
				if(x1 >= wx1 && y1 >= wy1 && x2 <= wx2 && y2 <= wy2) {
					ok=false;
					break;
				}
			}
			if(ok) {
				vis[nx][ny] = true;
				parent[nx][ny] = cur;
				Q.push(make_pair(nx,ny));
			}
		}
	}
	return 0;
}

int main(int argc, char *argv[]) {
	int sx, sy, tx, ty, ans;
	while(scanf("%d%d",&sy,&sx)==2) {
		if(sx==0 && sy==0) break;		
		memset(vis,false,sizeof(vis));
		scanf("%d%d",&ty,&tx);
		for(int i = 0; i < nwall; ++i)
			scanf("%d%d%d%d",&wall[i][0],&wall[i][1],&wall[i][2],&wall[i][3]);
		if( bfs(sx,sy,tx,ty) ) {
			int x=tx, y=ty;
			while(x!=sx||y!=sy) {
				int nx = parent[x][y].first;
				int ny = parent[x][y].second;
				if(x==nx && y==ny-1) path.push('W');
				else if(x==nx && y==ny+1) path.push('E');
				else if(x==nx-1 && y==ny) path.push('N');
				else if(x==nx+1 && y==ny) path.push('S');
				x=nx;
				y=ny;
			}
			while(!path.empty()) {
				putchar(path.top());
				path.pop();
			}
			putchar('\n');		
		}
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

