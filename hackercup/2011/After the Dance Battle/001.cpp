#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <cstring>
#include <cstdio>
#include <utility>
using namespace std;

typedef pair<int,int> pii;
vector<pii> adj[20];
char B[105][105];
int D[105][105];
int R, C;
int dr[] = {+1,-1,+0,+0};
int dc[] = {+0,+0,+1,-1};

int bfs(int sr, int sc, int tr, int tc) {
	memset(D,-1,sizeof(D));
	queue<pii> Q;
	Q.push(pii(sr,sc));
	D[sr][sc] = 0;
	while(!Q.empty()) {
		pii cur = Q.front(); Q.pop();
		int r = cur.first;
		int c = cur.second;
		if(r==tr && c==tc) return D[r][c];
		if(B[r][c]>='1' && B[r][c] <= '9') {
			int color = B[r][c]-'0';
			for(int i = 0; i < adj[color].size(); ++i) {
				int nr = adj[color][i].first;
				int nc = adj[color][i].second;
				if(D[nr][nc]<0) {
					Q.push(pii(nr,nc));
					D[nr][nc] = D[r][c]+1;
				}
			}
		}
		for(int i = 0; i < 4; ++i) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if(nr >= R || nr < 0 || nc >= C || nc < 0 || B[nr][nc]=='W') continue;
			if(D[nr][nc]<0) {
				Q.push(pii(nr,nc));
				D[nr][nc] = D[r][c]+1;
			}
		}
	}
	return -1;
}

int main() {
	int TC, sr, sc, tr, tc;
	scanf("%d",&TC);
	while(TC-- > 0) {
	
		scanf("%d%d",&R,&C);
		for(int i = 0; i < R; ++i)
			scanf("%s",B[i]);
			
		for(int i = 0; i < 20; ++i)
			adj[i].clear();
		
		for(int i = 0; i < R; ++i) {
			for(int j = 0; j < C; ++j) {
				if(B[i][j]>='1' && B[i][j] <= '9') {
					int k = B[i][j]-'0';
					adj[k].push_back(pii(i,j));
				}
				if(B[i][j]=='S') {
					sr=i;
					sc=j;
				}
				if(B[i][j]=='E') {
					tr=i;
					tc=j;
				}
			}
		}
		printf("%d\n",bfs(sr,sc,tr,tc));
	}
	return 0;
}
