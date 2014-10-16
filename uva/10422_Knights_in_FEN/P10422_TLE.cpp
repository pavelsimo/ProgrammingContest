/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10422  C++  "Graph Theory, BFS, Bitmask" */
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

const int n=5, dir=8;
char buf[32];
int dx[] = {+1,+1,-1,-1,+2,+2,-2,-2};
int dy[] = {+2,-2,+2,-2,+1,-1,+1,-1};
bool vis[1<<25][5][5];

struct State {
	int mask, i, j, d;
	State(int _mask, int _i, int _j, int _d) : mask(_mask), i(_i), j(_j), d(_d) {}
};

int bfs(State &dst) {
	memset(vis,false,sizeof(vis));
	State src(549855,2,2,0);
	queue<State> Q;
	Q.push(src);
	vis[549855][2][2] = true;
	while(!Q.empty()) {
		State cur = Q.front(); Q.pop();
		if(cur.mask==dst.mask && cur.i==dst.i && cur.j==dst.j) 
			return cur.d;
		if(cur.d >= 10) continue; 
		for(int d = 0; d < dir; ++d) {
			int nx=cur.i+dx[d];
			int ny=cur.j+dy[d];
			if(nx >= n || ny >= n || nx < 0 || ny < 0) continue;
			int nmask = cur.mask;
			if((nmask&(1<<(nx*n + ny)))) nmask|=1<<(cur.i*n + cur.j);
			nmask &=~(1<<(nx*n + ny));
			State ns(nmask,nx,ny,cur.d+1);
			if(!vis[nmask][nx][ny]) {
				vis[nmask][nx][ny] = true;
				Q.push(ns);
			}
		}
	}
	return -1;
}

int main(int argc, char *argv[]) {
	int TC, ans;
	gets(buf);
	sscanf(buf,"%d",&TC);
	while(TC-- > 0) {
		State dst(0,0,0,0);
		for(int i = 0; i < n; ++i) {
			gets(buf);
			for(int j = 0; j < n; ++j) {
				if(buf[j]=='1') dst.mask|=1<<(n*i+j);
				else if(buf[j]==' ') {
					dst.i=i;
					dst.j=j;
				}
			}
		}
		ans=bfs(dst);
		if(ans>=0) printf("Solvable in %d move(s).\n",ans);
		else printf("Unsolvable in less than 11 move(s).\n");
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

