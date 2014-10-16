/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  15240 10048  C++  "Graphs MST" */
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
#define present(container, element) (container.find(element) != container.end()) 
#define cpresent(container, element) (find(ALL(container),element) != container.end()) 
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }
typedef pair<int,int> ii;
typedef vector<ii> vii;

#define N 1002
#define INF 10000000
int mst[N][N];
int D[N][N];
int visited[N][N];
int path[N][N];


struct Edge {
    int i;
    int j;
    int w;
    Edge(int _i, int _j, int _w) 
        : i(_i), j(_j), w(_w) { } 
    bool operator<(const Edge &b) const {
        return b.w < w;
    }
};

struct DisjointSet {
    
    map<int,int> parent;
    map<int,int> rank;

    void make_set(int v) {
        parent[v] = v;
        rank[v] = 0;
    }

    int find_set(int u) {
        int& p = parent[u];
        if ( u != p )
            p = find_set(p); // path compresion
        return p;
    }

    bool union_set(int u, int v) {
        int u_root = find_set(u);
        int v_root = find_set(v);
        if ( u_root == v_root )
            return false;
        int u_rank = rank[u];
        int v_rank = rank[v];
        if ( u_rank > v_rank ) {
            parent[v_root] = u_root;
        } else {
            parent[u_root] = v_root;
            if ( u_rank == v_rank ) 
                rank[v] = rank[u] + 1;
        }
        return true;
    }
};

void kruskal(int n) {
    DisjointSet dset;
    priority_queue<Edge> Q;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if (D[i][j]!=-1) {
                Q.push(Edge(i,j,D[i][j]));
            }
        }
    }
    for(int i = 1; i <= n; ++i)
        dset.make_set(i);
    while ( !Q.empty() ) {
        Edge s = Q.top();
        Q.pop();
        if ( dset.union_set(s.i,s.j) )
            mst[s.i][s.j] = mst[s.j][s.i] = s.w;
    }
}

int dfs(int start, int end, int nvertex) {
    int res = 0;
    stack<int> stack;
    stack.push(start);
    while ( !stack.empty() ) {
        int s = stack.top();
        if ( s == end ) 
            return res;
        stack.pop();
        for(int i = 1; i <= nvertex; ++i) {
            if ( mst[s][i] != -1 && visited[s][i] == 0 ) {
                visited[s][i] = 1;
                res = max(res,mst[s][i]);
                stack.push(i);
            }
        }
    }
    return -1;
}   
/*
    Debido a que se pueden realizar hasta 10,000 query's
    este algoritmo no es conveniente ya que cada llamada al dfs() 
    es bastante costosa por lo que se decidio hacer otra 
    implementacion basada en Floyd-Warshall ver Main2.cpp
*/
int main() {
    int c,s,q;
    int v,u,w;
    int k = 0;
    while ( scanf("%d %d %d\n",&c,&s,&q) == 3 ) {
        if ( c == 0 && s == 0 && q == 0 ) break;
        if ( k != 0 )
            printf("\n");
        memset(D,-1,sizeof(D));
        memset(mst,-1,sizeof(mst));
        memset(path,-1,sizeof(mst));
        memset(visited,0,sizeof(visited));
        for(int i = 0; i < s; ++i) {
            scanf("%d %d %d\n",&v,&u,&w);
            D[v][u] = D[u][v] = w;
        }     
        kruskal(c);
        printf("Case #%d\n",++k);
        for(int i = 0; i < q; ++i) {
            memset(visited,0,sizeof(visited));
            scanf("%d %d\n",&v,&u);
            int x = dfs(v,u,c);
            if ( x == -1 )
                printf("no path\n");
            else
                printf("%d\n",x);
        }
    }
    return 0;
}
/* @END_OF_SOURCE_CODE */
