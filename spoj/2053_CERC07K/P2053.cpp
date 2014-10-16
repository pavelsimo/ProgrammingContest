/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ CERC07K C++ "Graph Theory, BFS" */
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

int N, M;
const int MAXN = 128;
const string colors = "BYRG";
char B[MAXN][MAXN];
bool seen[MAXN][MAXN][1<<4];
int dr[] = {+1,+0,-1,+0};
int dc[] = {+0,+1,+0,-1};

struct State {
    int row, col, key_mask, cost;
    State(int _r, int _c, int _key_mask, int _cost) :
        row(_r), col(_c), key_mask(_key_mask), cost(_cost) { }
};

int bfs(int rsrc, int csrc) {
    memset(seen,false,sizeof(seen));
    queue<State> Q;
    Q.push(State(rsrc,csrc,0,0));
    seen[rsrc][csrc][0] = true;
    while(!Q.empty()) {
        State cur = Q.front(); Q.pop();
        if(B[cur.row][cur.col] == 'X')
            return cur.cost;
        for(int d = 0; d < 4; ++d) {
            int nr = cur.row + dr[d];
            int nc = cur.col + dc[d];
            if(nr < 0 || nr >= N || nc < 0 || nc >= M 
                || B[nr][nc]=='#') continue;
            State nxt(nr, nc, cur.key_mask, cur.cost + 1);
            size_t p = colors.find(toupper(B[nxt.row][nxt.col]));
            if (p != string::npos) {
                if (isupper(B[nxt.row][nxt.col]))
                    if (!(cur.key_mask & (1 << p)))
                        continue;
                nxt.key_mask |= (1 << p);
            }
            if(!seen[nxt.row][nxt.col][nxt.key_mask]) {
                Q.push(nxt);
                seen[nxt.row][nxt.col][nxt.key_mask] = true;            
            }
        }
    }
    return -1;
}

int main(int argc, char *argv[]) {  
    int rsrc, csrc, res;
    while(scanf("%d%d",&N,&M)==2) {
        if(N==0 && M==0) break;
        for(int i = 0; i < N; ++i) {
            scanf("%s",B[i]);
            for(int j = 0; j < M; ++j) {
                if(B[i][j]=='*') {
                    rsrc = i;
                    csrc = j;
                }
            }
        }
        res = bfs(rsrc,csrc);
        if(res >= 0) printf("Escape possible in %d steps.\n",res);
        else puts("The poor student is trapped!");
    }
    return 0;
}
/* @END_OF_SOURCE_CODE */
