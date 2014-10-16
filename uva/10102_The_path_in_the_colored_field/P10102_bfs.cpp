/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10102  C++  "Graph Theory, BFS" */
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
const int dir = 4;
char buf[maxn];
char B[maxn][maxn];
int D[maxn][maxn];
int dx[] = {+1,-1,+0,+0};
int dy[] = {+0,+0,+1,-1};
int n;
vii src;

void bfs() {
	memset(D,-1,sizeof(D));
	queue<ii> Q;
	for(int k = 0; k < src.size(); ++k) {
		Q.push(src[k]);
		D[src[k].first][src[k].second]=0;
	}
	while(!Q.empty()) {
		ii cur = Q.front(); Q.pop();
		int x = cur.first;
		int y = cur.second;
		for(int d = 0; d < dir; ++d) {
			int nx=x+dx[d];
			int ny=y+dy[d];
			if(nx >= n || ny >= n || nx < 0 || ny < 0 || D[nx][ny]>=0) continue;
			D[nx][ny]=D[x][y]+1;
			Q.push(ii(nx,ny));
		}
	}
}


int main(int argc, char *argv[]) {
	int ans;
	while(gets(buf)) {
		if(sscanf(buf,"%d",&n)!=1) break;
		src.clear();
		for(int i = 0; i < n; ++i) {
		   gets(B[i]);
			for(int j = 0; j < n; ++j) {
				if(B[i][j]=='3') src.push_back(ii(i,j));
			}
		}
		bfs();
		ans=0;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				if(B[i][j]=='1') 
					ans=max(ans,D[i][j]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

