/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ MAWORK C++ "Graph Theory, BFS" */
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

const int MOD = 5040; // lcm(1*2, 2*2, 2*3, ..., 2*d)
const int MAXN = 26;
const string digits = "0123456789";
const int dr[] = {+0,+1,-1,+0,+0};
const int dc[] = {+0,+0,+0,+1,-1};
int N;
bool D[MOD][MAXN][MAXN];
char B[MAXN][MAXN], V[MAXN][MAXN];

struct State {
    int row, col, time;
    State(int _row, int _col, int _time) :
        row(_row), col(_col), time(_time) { }
};

int bfs() {
    memset(D,false,sizeof(D));
    queue<State> Q;
    Q.push(State(0,0,0));
    while(!Q.empty()) {
        State cur = Q.front();
        Q.pop();
        int time = cur.time;
        if(D[cur.time%MOD][cur.row][cur.col]) continue;
        D[cur.time%MOD][cur.row][cur.col] = true;
        if(cur.row == N-1 && cur.col == N-1) 
            return time;
        for(int d = 0; d < 5; ++d) {
            State nxt(cur.row + dr[d], cur.col + dc[d], cur.time + 1);
            if(nxt.row < 0 || nxt.row >= N || nxt.col < 0 || nxt.col >= N) continue;
            if(B[nxt.row][nxt.col] == '*' && V[nxt.row][nxt.col]=='0') continue;
            int p = V[nxt.row][nxt.col]-'0';
            if(p > 0 && B[nxt.row][nxt.col]=='.') {
                int t = (time + 1) / p;
                if(t%2!=0) continue;
            } else if(B[nxt.row][nxt.col]=='*') {
                int t = (time + 1)/p;
                if(t%2==0) continue;
            }                
            Q.push(nxt);
        }
    }
    return -1;
}

int main(int argc, char *argv[]) {  
    int TC, res;
    scanf("%d",&TC);
    while(TC-- > 0) {
        scanf("%d",&N);
        for(int i = 0; i < N; ++i)
            scanf("%s", &B[i]);
        for(int i = 0; i < N; ++i)
            scanf("%s", &V[i]);
        res = bfs();
        if(res >= 0) printf("%d\n",res);
        else puts("NO");
    }
    return 0;
}
/* @END_OF_SOURCE_CODE */
