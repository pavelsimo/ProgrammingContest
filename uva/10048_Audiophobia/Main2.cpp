/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  15240 10048  C++  "Graphs Floyd-Warshall" */
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
int D[N][N];

void floyd(int n) {
    for(int k = 1; k <= n; ++k) {
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) { 
                D[i][j] = min(D[i][j],max(D[i][k],D[k][j]));
            }
        }
    }
}

int main() {
    int c,s,q;
    int v,u,w;
    int k = 0;
    while ( scanf("%d %d %d\n",&c,&s,&q) == 3 ) {
        if ( c == 0 && s == 0 && q == 0 ) break;
        if ( k != 0 )
            printf("\n");
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < N; ++j)
                D[i][j] = INF;
        for(int i = 0; i < s; ++i) {
            scanf("%d %d %d\n",&v,&u,&w);
            D[v][u] = D[u][v] = w;
        }     
        floyd(c);
        printf("Case #%d\n",++k);
        for(int i = 0; i < q; ++i) {
            scanf("%d %d\n",&v,&u);
            int x = D[v][u];
            if ( x == INF )
                printf("no path\n");
            else
                printf("%d\n",x);
        }
    }
    return 0;
}
/* @END_OF_SOURCE_CODE */

