/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  15240 260  C++  "DFS Flood Fill" */
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
char v[N][N];
int D[N][N];

void dfs(int i, int j, int nrows, char c) {
     if ( i < 0 || i >= nrows || j < 0 || j >= nrows || D[i][j] != 0 || v[i][j] != c )
        return;      
    if ( c == 'w' ) D[i][j] = 1;
    else D[i][j] = 2;
    dfs(i-1, j-1, nrows, c);
    dfs(i-1, j, nrows, c);
    dfs(i, j-1, nrows, c);
    dfs(i, j+1, nrows, c);
    dfs(i+1, j, nrows, c);
    dfs(i+1, j+1, nrows, c);
}

int main() {
    int nrows;
    int ncases = 1;
    while( cin >> nrows ) {
        memset(D, 0, sizeof(D));
        if (nrows == 0) break;
        for(int i = 0; i < nrows; ++i)           
            for(int j = 0; j < nrows; ++j)
                cin >> v[i][j];
        for(int i = 0; i < nrows; ++i) {
            if (v[i][0] == 'w')
               dfs(i,0,nrows,v[i][0]);
            if (v[0][i] == 'b')
               dfs(0,i,nrows,v[0][i]);
        }
        for(int i = 0; i < nrows; ++i) {
            if (D[i][nrows-1] == 1) {
               printf("%d W\n", ncases);
               break;
            }
            if (D[nrows-1][i] == 2) {
               printf("%d B\n", ncases);
               break;     
            }
        }
        ncases++;
    }
  return 0;
}
/* @END_OF_SOURCE_CODE */
