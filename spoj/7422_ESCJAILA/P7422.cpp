/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ ESCJAILA C++ "Graph Theory, BFS" */
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

int N, M;
const int MAXN=128, OPEN=1, CLOSE=0;
char buf[MAXN], B[MAXN][MAXN];
bool D[MAXN][MAXN][2];
int dr[] = {+1,-1,+0,+0};
int dc[] = {+0,+0,+1,-1};

struct Node {
    int r, c, doors, cost;
    Node(int _r, int _c, int _doors, int _cost) : 
        r(_r), c(_c), doors(_doors), cost(_cost) { }
};

int bfs(int rsrc, int csrc) {
    memset(D,false,sizeof(D));
    queue<Node> Q;
    Q.push(Node(rsrc,csrc,CLOSE,0));
    while(!Q.empty()) {
        Node cur = Q.front(); 
        Q.pop();
        if(D[cur.r][cur.c][cur.doors]) continue;
        if(cur.r == 0 || cur.r == N-1 || cur.c == 0 || cur.c == M-1) 
            return cur.cost + 1;
        D[cur.r][cur.c][cur.doors] = true;
        int ndoors = cur.doors;
        if(B[cur.r][cur.c] == 'O') ndoors = OPEN;
        else if(B[cur.r][cur.c] == 'C') ndoors = CLOSE;
        for(int d = 0; d < 4; ++d) {
            int nr = cur.r + dr[d];
            int nc = cur.c + dc[d];            
            if(B[nr][nc]=='W') continue;
            if(ndoors==CLOSE && B[nr][nc]=='D') continue;
            Node nxt(nr, nc, ndoors, cur.cost + 1);
            Q.push(nxt);
        }
    }
    return -1;
}

int main(int argc, char *argv[]) {
    int rsrc, csrc;
    while(gets(buf)) {
        sscanf(buf,"%d%d",&N,&M);
        if(N==-1 && M==-1) break;
        for(int i = 0; i < N; ++i) {
            gets(B[i]);
            for(int j = 0; j < M; ++j) {
                if(B[i][j]=='H') {
                    rsrc = i;
                    csrc = j;
                }
            }
        }
        printf("%d\n",bfs(rsrc,csrc));
    }
    return 0;
}
/* @END_OF_SOURCE_CODE */
