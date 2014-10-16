/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  15240 784  C++  "DFS Flood Fill" */
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

char v[31][81];

void dfs(char v[31][81], int i, int j, int nrows, int ncols) {
  if ( i >= nrows || i < 0 || j >= ncols || j < 0 
        || v[i][j] != ' ' )
    return;
  v[i][j] = '#';
  dfs(v, i+1, j, nrows, ncols);
  dfs(v, i-1, j, nrows, ncols);
  dfs(v, i, j+1, nrows, ncols);
  dfs(v, i, j-1, nrows, ncols);
}

void print_board(char v[31][81], int nrows, int ncols) {
  int sx = 0;
  int sy = 0;
  int ok = 0;
  for(int i = 0; i < nrows; ++i) {
    for(int j = 0; j < ncols && v[i][j] != '\0'; ++j) {
      if ( v[i][j] == '*' ) {
        sx = i;
        sy = j;
        ok = 1;
        break;
      }
    } 
    if ( ok ) break;
  }
  v[sx][sy] = ' ';
  dfs(v,sx,sy,nrows,ncols);
  for(int i = 0; i < nrows; ++i) {
    for(int j = 0; j < ncols && v[i][j] != '\0'; ++j) 
      printf("%c",v[i][j]);
    printf("\n");
  }
}

void clean(char v[31][81]) {
  for(int i = 0; i < 31; ++i)
    for(int j = 0; j < 81; ++j)
      v[i][j] = '\0';
}

int main() {
    int nboards;
    scanf("%d\n", &nboards);
    for(int k = 0; k < nboards; ++k) {  
      int i, j;
      int cols = 0;
      char line[81];
      clean(v);
      for(i = 0; true; ++i) {                
        gets(line);
        if ( line[0] == '_' ) break;
        for (j = 0; line[j] != '\0'; ++j)
          v[i][j] = line[j];
        cols = max(cols,j);
      }
      print_board(v,i,cols);
      printf("%s\n",&line);
    }
  return 0;
}
/* @END_OF_SOURCE_CODE */
