/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ CHMAZE C++ "Graph Theory, BFS" */
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

const int MAXN = 64;
int N, M, P;
char buf[MAXN], B[MAXN][MAXN][MAXN]; // PATTERN, N, M
bool seen[MAXN][MAXN][MAXN];
int dr[] = {+0,+1,-1,+0,+0};
int dc[] = {+0,+0,+0,+1,-1};

struct State {
    int r, c, pattern, cost;
    State(int _r, int _c, int _pattern, int _cost) :
        r(_r), c(_c), pattern(_pattern), cost(_cost) { }
};

int bfs() {
    memset(seen,false,sizeof(seen));
    queue<State> Q;
    Q.push(State(0,0,0,0));
    seen[0][0][0] = true;
    while(!Q.empty()) {
        State cur = Q.front(); Q.pop();
        if(cur.r == N-1 && cur.c == M-1) 
            return cur.cost;
        int nxt_pattern = (cur.pattern+1)%P;
        for(int d = 0; d < 5; ++d) {
            int nr = cur.r + dr[d];
            int nc = cur.c + dc[d];
            if(nr >= N || nr < 0 || nc >= M || nc < 0 || 
                seen[nxt_pattern][nr][nc] || B[nxt_pattern][nr][nc]!='0') continue;
            seen[nxt_pattern][nr][nc] = true;
            Q.push(State(nr, nc, nxt_pattern, cur.cost + 1));
        }
    }
    return -1;
}

int main(int argc, char *argv[]) {  
    int res;
    for(int tc = 1; scanf("%d%d%d",&N,&M,&P) == 3; ++tc) {
        if(N==0 && M==0 && P==0) break;
        for(int i = 0; i < P; ++i) {
            for(int j = 0; j < N; ++j) {
                scanf("%s",&B[i][j]);
            }
        }
        res = bfs();
        printf("Case %d: ",tc);
        if(res >= 0) printf("Luke and Leia can escape in %d steps.\n",res);
        else puts("Luke and Leia cannot escape.");
    }
    return 0;
}
/* @END_OF_SOURCE_CODE */
