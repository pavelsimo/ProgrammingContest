/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ BYTESE1 C++ "Graph Theory, BFS" */
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

const int MAXN = 104;
const int dr[] = {+1, -1, +0, +0};
const int dc[] = {+0, +0, +1, -1};
int N, M, T;
int D[MAXN][MAXN], B[MAXN][MAXN];

struct State {
    int row, col, dist;
    State(int _row, int _col, int _dist) : 
        row(_row), col(_col), dist(_dist) { }
    bool operator< (const State &T) const {
        if(T.dist != dist) 
            return T.dist < dist;
        if(T.row != row) 
            return T.row < dist;
        return T.col < dist;
    }
};

int bfs(int r, int c) {
    memset(D,-1,sizeof(D));
    priority_queue<State> Q;
    Q.push(State(0,0,B[0][0]));
    D[0][0] = B[0][0];
    while(!Q.empty()) {
        State cur = Q.top(); 
        Q.pop();
        int dist = D[cur.row][cur.col];
        if(cur.row == r && cur.col == c) 
            return dist;
        if(dist < cur.dist)
            continue;
        for(int d = 0; d < 4; ++d) {
            int nr = cur.row + dr[d];
            int nc = cur.col + dc[d];
            if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            State nxt(nr, nc, dist + B[nr][nc]);
            if(D[nxt.row][nxt.col] < 0 || D[nxt.row][nxt.col] > nxt.dist) {
                D[nxt.row][nxt.col] = nxt.dist;
                Q.push(nxt);
            }
        }
    }
    return -1;
}

int main(int argc, char *argv[]) {  
    int TC, r, c, res;
    scanf("%d",&TC);
    while(TC-- > 0) {
        scanf("%d%d",&N,&M);
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < M; ++j) {
                scanf("%d",&B[i][j]);
            }
        }
        scanf("%d %d %d",&r, &c, &T);
        --r; --c;
        res = T-bfs(r,c);
        if(res >= 0) 
            printf("YES\n%d\n",res);
        else 
            puts("NO");
    }    
    return 0;
}
/* @END_OF_SOURCE_CODE */
