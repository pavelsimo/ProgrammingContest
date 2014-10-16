/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11352  C++  "Graph Theory, BFS" */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <utility>
using namespace std;

typedef pair<int,int> node;
const int maxn = 102;
char buf[1024];
char B[maxn][maxn];
bool vis[maxn][maxn];
int D[maxn][maxn];
int dir = 8;
int dx[] = {+1,+0,-1,+0,+1,+1,-1,-1};
int dy[] = {+0,+1,+0,-1,+1,-1,+1,-1};
int hdx[] = {+1,+1,-1,-1,+2,+2,-2,-2};
int hdy[] = {+2,-2,+2,-2,+1,-1,+1,-1};
int n, m;

int bfs(int sx, int sy, int tx, int ty) {
	queue<node> Q;
	Q.push(make_pair(sx,sy));
	vis[sx][sy]=true;
	D[sx][sy]=0;
	while(!Q.empty()) {
		node cur = Q.front(); Q.pop();
		int cx = cur.first;
		int cy = cur.second;
		if(cx==tx && cy==ty) return D[cx][cy];
		for(int d = 0; d < dir; ++d) { 
			int nx = cx+dx[d];
			int ny = cy+dy[d];
			if(nx < 0 || ny < 0 || nx >= n || ny >= m || vis[nx][ny]) continue;
			vis[nx][ny]=true;
			D[nx][ny] = D[cx][cy]+1;
			Q.push(make_pair(nx,ny));
		}
	}
	return -1;
}

int main(int argc, char *argv[]) {
	int TC, sx, sy, tx, ty, ans;
	gets(buf);
	sscanf(buf,"%d",&TC);
	while(TC-- > 0) {
		memset(vis,false,sizeof(vis));
		memset(D,-1,sizeof(D));
		
      gets(buf);
		sscanf(buf,"%d%d",&n,&m);
		
		for(int i = 0; i < n; ++i) 
			gets(B[i]);
		
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				if(B[i][j]=='A') {
					sx=i;
					sy=j;
				} else if(B[i][j]=='B') {
					tx=i;
					ty=j;
				} else if(B[i][j]=='Z') {
					int nx,ny;
					vis[i][j]=true;
					for(int d=0; d < dir; ++d) {
						nx=i+hdx[d];
						ny=j+hdy[d];
						if(nx < 0 || ny < 0 || nx >= n || ny >= m || B[nx][ny]=='A' || B[nx][ny]=='B' ) continue;
						vis[nx][ny]=true;
					}
				}
			}
		}
		ans = bfs(sx,sy,tx,ty);
		if(ans>=0) printf("Minimal possible length of a trip is %d\n",ans);
		else puts("King Peter, you can't go now!");
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
