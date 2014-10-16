/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  15240 10067  C++  "Graphs BFS" */
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

struct Node {
  int a;
  int b;
  int c;
  int d;
  Node(int na, int nb, int nc, int nd) {
    a = na;
    b = nb;
    c = nc;
    d = nd;
  }     
};

int D[10][10][10][10];
int ns1[4];
int ns2[4];

int bfs(const Node &start, const Node &t) {    
    queue<Node> Q;
    D[start.a][start.b][start.c][start.d] = 0;
    Q.push(start);
    while ( !Q.empty() ) {
        Node s = Q.front();
        if ( s.a == t.a && s.b == t.b && s.c == t.c && s.d == t.d )
           return D[s.a][s.b][s.c][s.d];
        Q.pop();
        for(int i = 0; i < 4; ++i) {
            ns1[0] = s.a; ns1[1] = s.b; ns1[2] = s.c; ns1[3] = s.d;
            ns2[0] = s.a; ns2[1] = s.b; ns2[2] = s.c; ns2[3] = s.d;
            ns1[i] = ((ns1[i]+1)%10);
            ns2[i] = ((10+ns2[i]-1)%10);
            if( D[ns1[0]][ns1[1]][ns1[2]][ns1[3]] == -1 ) {
                D[ns1[0]][ns1[1]][ns1[2]][ns1[3]] = D[s.a][s.b][s.c][s.d] + 1;
                Q.push(Node(ns1[0],ns1[1],ns1[2],ns1[3]));        
            }
            if( D[ns2[0]][ns2[1]][ns2[2]][ns2[3]] == -1 ) {
                D[ns2[0]][ns2[1]][ns2[2]][ns2[3]] = D[s.a][s.b][s.c][s.d] + 1;
                Q.push(Node(ns2[0],ns2[1],ns2[2],ns2[3]));      
            }
        }
    }
    return -1;
}

int main() {
    int n;
    int m;
    int a,b,c,d;
    scanf("%d\n",&n);
    for(int i = 0; i < n; ++i) {
        memset(D, -1, sizeof(D));
        scanf("%d %d %d %d\n",&a,&b,&c,&d);
        Node start(a,b,c,d);
        scanf("%d %d %d %d\n",&a,&b,&c,&d);
        Node target(a,b,c,d);
        scanf("%d\n",&m);  
        for(int j = 0; j < m; ++j) {
            scanf("%d %d %d %d\n",&a,&b,&c,&d);
            D[a][b][c][d] = -2;
        }
        printf("%d\n",bfs(start,target));;
    }
    return 0;
}
/* @END_OF_SOURCE_CODE */
