/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ CATM C++ "Graph Theory, BFS" */
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
const int dr[] = {+1,-1,+0,+0};
const int dc[] = {+0,+0,+1,-1};
int N, M;
int MD[MAXN][MAXN], CD[MAXN][MAXN];

struct State {
    int row, col;
    State(int _row = 0, int _col = 0) :
        row(_row), col(_col) { }
};

void mbfs(State mouse) {
    memset(MD,-1,sizeof(MD));
    queue<State> Q;
    Q.push(mouse);
    MD[mouse.row][mouse.col] = 0;
    while(!Q.empty()) {
        State cur = Q.front();
        Q.pop();
        for(int d = 0; d < 4; ++d) {
            State nxt(cur.row + dr[d], cur.col + dc[d]);
            if(nxt.row < 0 || nxt.row >= N || nxt.col < 0 || nxt.col >= M) continue;
            if(MD[nxt.row][nxt.col] < 0) {
                MD[nxt.row][nxt.col] = MD[cur.row][cur.col] + 1;
                Q.push(nxt);
            }
        }
    }
}

void cbfs(State cat1, State cat2) {
    memset(CD,-1,sizeof(CD));
    queue<State> Q;
    Q.push(cat1);
    Q.push(cat2);
    CD[cat1.row][cat1.col] = 0;
    CD[cat2.row][cat2.col] = 0;
    while(!Q.empty()) {
        State cur = Q.front();
        Q.pop();
        for(int d = 0; d < 4; ++d) {
            State nxt(cur.row + dr[d], cur.col + dc[d]);
            if(nxt.row < 0 || nxt.row >= N || nxt.col < 0 || nxt.col >= M) continue;
            if(CD[nxt.row][nxt.col] < 0) {
                CD[nxt.row][nxt.col] = CD[cur.row][cur.col] + 1;
                Q.push(nxt);
            }
        }
    }    
}

int main(int argc, char *argv[]) {  
    int TC;
    State mouse, cat1, cat2;
    while(scanf("%d%d",&N,&M)==2) {
        scanf("%d",&TC); 
        while(TC-- > 0) {
            scanf("%d%d%d%d%d%d",&mouse.row, &mouse.col, &cat1.row, &cat1.col, &cat2.row, &cat2.col); 
            --mouse.row; --mouse.col; 
            --cat1.row; --cat1.col; --cat2.row; --cat2.col;
            mbfs(mouse);
            cbfs(cat1,cat2);
            bool escaped  = false;
            for(int i = 0; i < N; ++i) {
                if(MD[i][0] < CD[i][0]) {
                    escaped = true;
                    break;
                }
                if(MD[i][M-1] < CD[i][M-1]) {
                    escaped = true;
                    break;
                }   
            }
            for(int i = 0; i < M; ++i) {
                if(MD[0][i] < CD[0][i]) {
                    escaped = true;
                    break;
                }
                if(MD[N-1][i] < CD[N-1][i]) {
                    escaped = true;
                    break;
                }
            }
            puts(escaped ? "YES": "NO");
        }
    }
    return 0;
}
/* @END_OF_SOURCE_CODE */
