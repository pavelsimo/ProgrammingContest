/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  15240 544  C++  "Floyd-Warshall Graph" */
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
#define RFORE(t,i) for(typeof(t.rbegin())i=t.rbegin();i!=t.rend();++i)
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

#define N 201
#define INF 100000000
int D[N][N];

void floyd(int n) {
    for(int k = 0; k < n; ++k) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                D[i][j] = max(D[i][j],min(D[i][k],D[k][j]));
            }            
        }
    }
}

int main() {
    int n,m,w,cas=0;
    string v,u;
    while(scanf("%d %d\n",&n,&m) == 2 ) {
        if( n==0 && m==0 ) break;                   
        map<string,int> vset;
        map< pair<string, string>, int> q;
        int vcnt = 0;
        memset(D, -1, sizeof(D));
        for(int i = 0; i < m; ++i) {
            cin >> v >> u >> w;
            vset[v] = 0;
            vset[u] = 0;
            q[pair<string,string>(v,u)] = w;
        }
        FORE(vset, it)
            vset[it->first] = vcnt++;
        FORE(q, it)
            D[vset[it->first.first]][vset[it->first.second]] = D[vset[it->first.second]][vset[it->first.first]] = it->second;
        floyd(n);
        cin >> v >> u;
        printf("Scenario #%d\n",++cas);
        printf("%d tons\n",D[vset[v]][vset[u]]);
        printf("\n");
    }
    return 0;
}
/* @END_OF_SOURCE_CODE */
