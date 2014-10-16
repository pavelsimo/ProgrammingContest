/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  15240 10336  C++  "DFS Flood Fill" */
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

#define N 101
#define M 101

char v[N][M];
int visited[N][N];
int freq[26];
void dfs(char v[N][M], int i, int j, int nrows, int ncols, char target) {
  if ( i >= nrows || i < 0 || j >= ncols || j < 0 
        || v[i][j] != target || visited[i][j] == 0 )
    return;
  visited[i][j] = 0;
  dfs(v, i+1, j, nrows, ncols, target);
  dfs(v, i-1, j, nrows, ncols, target);
  dfs(v, i, j+1, nrows, ncols, target);
  dfs(v, i, j-1, nrows, ncols, target);
}

int main() {
  int nworld;
  int nrows, ncols;
  scanf("%d\n",&nworld);
  for(int k = 0; k < nworld; ++k) {
    cin >> nrows;
    cin >> ncols;
    memset(freq, 0, sizeof(freq));
    memset(visited, -1, sizeof(visited));
    if ( nrows == 0 && ncols == 0 ) break;
      for(int i = 0; i < nrows; ++i)
        for(int j = 0; j < ncols; ++j)
          cin >> v[i][j];

      for(int i = 0; i < nrows; ++i) {
        for(int j = 0; j < ncols; ++j) {
          if ( visited[i][j] == -1 ) {
            dfs(v,i,j,nrows,ncols,v[i][j]);
            freq[v[i][j]-'a']++;
          }
        }
      }
      map<int, string> D;
      for(int i = 0; i < 26; ++i) {
        char c = (char)i+'a';
        if ( freq[i] > 0 ) D[freq[i]] +=c; 
      }
      printf("World #%d\n",(k+1));
      RFORE(D,it) {
        string s = it->second;
        sort(s.begin(), s.end());
        for(int i = 0; i < s.size(); ++i)
          printf("%c: %d\n",s[i],it->first);
      }
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
