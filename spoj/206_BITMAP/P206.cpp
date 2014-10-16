/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ BITMAP C++ "Graph Theory, DFS, Flood Fill" */
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


typedef pair<int,int> PII;

const int MAXN = 190, INF = 0x2f2f2f2f;
char B[MAXN][MAXN], buf[MAXN];
int D[MAXN][MAXN];
queue<PII> Q;
int N, M;
int dx[] = {+1,-1,+0,+0};
int dy[] = {+0,+0,+1,-1};

void bfs() {
    while(!Q.empty()) {
        PII cur = Q.front(); Q.pop();
        for(int d = 0; d < 4; ++d) {
            int nx = cur.first + dx[d];
            int ny = cur.second + dy[d];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M || D[nx][ny] != INF) continue;
            Q.push(make_pair(nx,ny));
            D[nx][ny] = D[cur.first][cur.second] + 1;
        }
    }
}

int main(int argc, char *argv[]) {
    int TC;
    gets(buf);
    sscanf(buf,"%d",&TC);
    while(TC-- > 0) {
        gets(buf);
        sscanf(buf,"%d%d",&N,&M);
        memset(D,0x2f,sizeof(D));
        for(int i = 0; i < N; ++i) {
            gets(B[i]);
            for(int j = 0; j < M; ++j) {
                if(B[i][j]-'0') {
                    Q.push(make_pair(i,j));
                    D[i][j] = 0;
                }
            }
        }
        bfs();
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < M; ++j) {
                if(j > 0) putchar(' ');
                printf("%d",D[i][j]);
            }
            putchar('\n');
        }
        gets(buf);
    }
    return 0;
}
/* @END_OF_SOURCE_CODE */
