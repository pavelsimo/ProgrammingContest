/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  15240 572  C++  "DFS Flood Fill" */
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

#define N 101
#define M 101

char v[N][M];
int visited[N][N];

void dfs(char v[N][M], int i, int j, int nrows, int ncols) {
  if ( i >= nrows || i < 0 || j >= ncols || j < 0 
        || v[i][j] == '*' || visited[i][j] == 0 )
    return;
  visited[i][j] = 0;
  dfs(v, i+1, j, nrows, ncols);
  dfs(v, i-1, j, nrows, ncols);
  dfs(v, i, j+1, nrows, ncols);
  dfs(v, i, j-1, nrows, ncols);
  dfs(v, i-1, j+1, nrows, ncols);
  dfs(v, i+1, j-1, nrows, ncols);
  dfs(v, i+1, j+1, nrows, ncols);
  dfs(v, i-1, j-1, nrows, ncols);
}

int main() {
  int nrows, ncols;
  while ( cin >> nrows && cin >> ncols ) {
  if ( nrows == 0 && ncols == 0 ) break;
    for(int i = 0; i < nrows; ++i)
      for(int j = 0; j < ncols; ++j)
        cin >> v[i][j];
    int res = 0;
    memset(visited, -1, sizeof(visited));
    for(int i = 0; i < nrows; ++i) {
      for(int j = 0; j < ncols; ++j) {
        if ( v[i][j] == '@' && visited[i][j] == -1 ) {
          dfs(v,i,j,nrows,ncols);
          res++;
        }
      }
    }
    printf("%d\n",res);
  }
    
  return 0;
}
/* @END_OF_SOURCE_CODE */
