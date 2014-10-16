/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ IMAGE C++ "Graph Theory, DFS, Flood Fill" */
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <deque>
#include <numeric>
#include <iterator>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <climits>
#include <sys/time.h>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

const int MAXN = 30;
int N, M, res;
char B[MAXN][MAXN];
bool vis[MAXN][MAXN];
int dx[] = {+1,-1,+0,+0,+1,+1,-1,-1};
int dy[] = {+0,+0,+1,-1,+1,-1,+1,-1};

void dfs(int i, int j) {
    if(i < 0 || i >= N || j < 0 || j >= M || B[i][j] != 'X' || vis[i][j]) return; 
    vis[i][j] = true;
    for(int d = 0; d < 4; ++d) {
        int nx = i + dx[d];
        int ny = j + dy[d];
        if(nx < 0 || nx >= N || ny < 0 || ny >= M || B[nx][ny] == '.') res++;
    }
    for(int d = 0; d < 8; ++d)
        dfs(i + dx[d], j + dy[d]);
}

int main(int argc, char *argv[]) {
	int xsrc, ysrc;
    while(scanf("%d%d%d%d",&N,&M,&xsrc, &ysrc)==4) {
        if(N==0 && M==0 && xsrc==0 && ysrc==0) break;
        --xsrc; --ysrc;
        memset(vis,false,sizeof(vis));
        res = 0;
        for(int i = 0; i < N; ++i) scanf("%s",&B[i]);
        dfs(xsrc,ysrc);
        printf("%d\n",res);
    }
    return 0;
}
/* @END_OF_SOURCE_CODE */
