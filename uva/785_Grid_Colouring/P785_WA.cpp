/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  15240 785  C++  "DFS Flood Fill" */
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

#define N 35
#define M 85
char v[N][M];

void dfs(char v[N][M], int i, int j, int nrows, int ncols, char c) {
  if ( i >= nrows || i < 0 || j >= ncols || j < 0 )
    return;
  if ( v[i][j] == ' ' )
    v[i][j] = c;
  dfs(v, i+1, j, nrows, ncols, c);
  dfs(v, i-1, j, nrows, ncols, c);
  dfs(v, i, j+1, nrows, ncols, c);
  dfs(v, i, j-1, nrows, ncols, c);
}

void print_board(char v[N][M], int nrows, int ncols) {
  for(int i = 0; i < nrows; ++i) {
    for(int j = 0; j < ncols && v[i][j] != '\0'; ++j) {
      if ( v[i][j] != ' ' && v[i][j] != '_' ) {
        printf("(%d,%d)",i,j);
        dfs(v, i, j, nrows, ncols, v[i][j]);
      }
    }
  }
  for(int i = 0; i < nrows; ++i) {
    for(int j = 0; j < ncols && v[i][j] != '\0'; ++j) 
      printf("%c",v[i][j]);
    printf("\n");
  }
}

void clean(char v[N][M]) {
  for(int i = 0; i < N; ++i)
    for(int j = 0; j < M; ++j)
      v[i][j] = '\0';
}

int main() {
    int i, j;
    int cols = 0;
    char line[M];
    while(true) {  
      clean(v);
      for(i = 0; true; ++i) { 
        if ( gets(line) == NULL )
          return 0;
        if ( line[0] == '_' ) break;
        for (j = 0; line[j] != '\0' ; ++j)
          v[i][j] = line[j];
        cols = max(cols,j);
      }
      print_board(v,i,cols);
      printf("%s\n",&line);
    }
  return 0;
}
/* @END_OF_SOURCE_CODE */
