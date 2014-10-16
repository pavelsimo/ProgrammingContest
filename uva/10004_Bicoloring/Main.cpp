/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  15240 10004  C++  "Graphs BFS" */
#include <algorithm>
#include <numeric>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <cmath>
#include <complex>
#include <stack>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define N 201
int adjMatrix[N][N];
int color[N];
int visited[N];

int adj(int v) {
    for(int i = 0; i < N; ++i)
       if ( adjMatrix[v][i] == 1 && color[i] == -1 )
            return i; 
    return -1;
}

int bfs(int n) {
    memset(color, -1, sizeof(color));
    queue<int> q;
    q.push(0);
    color[0] = 0;
    while ( !q.empty() ) {
        int s = q.front();
        q.pop();
        int ns;
        while ((ns=adj(s)) != -1) {
            color[ns] = !color[s];            
            visited[ns] = 1;
            q.push(ns);
        }
    }
    for(int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if ( adjMatrix[i][j] == 1 )
                if ( color[i] == color[j] ) return 0;
    return 1;
}

int main() {
    int n, m, u, v;
    while (1) {
        scanf("%d\n%d\n", &n, &m);
        if ( n == 0 ) break;
        for(int i = 0; i < m; ++i) {
            scanf("%d %d\n",&v,&u);
            adjMatrix[u][v] = 1;
            adjMatrix[v][u] = 1;
        }
        if ( bfs(n) ) printf("BICOLORABLE.\n");
        else printf("NOT BICOLORABLE.\n");
        memset(adjMatrix, 0, sizeof(adjMatrix));
    }
    return 0;
}
/* @END_OF_SOURCE_CODE */
