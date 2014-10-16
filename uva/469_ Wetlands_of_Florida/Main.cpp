/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  15240 469  C++  "DFS Flood Fill" */
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

#define N 101
#define M 101

int D[N][M];
int visited[N][N];
vii memo;
int cnt = 0;

void dfs(vector<string> &v, vii &memo, int i, int j, int nrows, int ncols) {
    if ( i >= nrows || i < 0 || j >= ncols || j < 0  
        || v[i][j] == 'L' || visited[i][j] == 0 ) return;
    memo.push_back(ii(i,j));
    visited[i][j] = 0;
    cnt++;
    dfs(v, memo, i+1, j, nrows, ncols);
    dfs(v, memo, i-1, j, nrows, ncols);
    dfs(v, memo, i, j+1, nrows, ncols);
    dfs(v, memo, i, j-1, nrows, ncols);
    dfs(v, memo, i-1, j+1, nrows, ncols);
    dfs(v, memo, i+1, j-1, nrows, ncols);
    dfs(v, memo, i+1, j+1, nrows, ncols);
    dfs(v, memo, i-1, j-1, nrows, ncols);
}

int main() {
    int tcas,R,C;
    char line[128];
    scanf("%d\n",&tcas);
    for (int cas = 0; cas < tcas; ++cas) {
       vector<string> v;
       vii pts;
       int nrows = 0;
       int ncols = 0;
       while(1) {
           gets(line);
           if(line[0]!='W'&&line[0]!='L') break;
           v.push_back(line);
       }
       sscanf(line,"%d %d",&R,&C);
       pts.push_back(ii(R,C));   
       while(gets(line)) {
          if(!strlen(line)) break;
          sscanf(line,"%d %d",&R,&C);
          pts.push_back(ii(R,C));  
       }
       memset(visited, -1, sizeof(visited));
       memset(D, 0, sizeof(D));
       nrows = v.size();
       for(int i = 0; i < nrows; ++i) {
           ncols = v[i].size();
           for(int j = 0; j < ncols; ++j) {
               if ( v[i][j] == 'W' && visited[i][j] == -1 ) {      
                   dfs(v,memo,i,j,nrows,ncols);
                   for(int k = 0; k < memo.size(); ++k)
                       D[memo[k].first][memo[k].second] = cnt;
                   cnt = 0;
                   memo.clear();
               }
           }
       }
       for (int i = 0; i < pts.size(); ++i) {
           int ni = pts[i].first;
           int nj = pts[i].second;
           printf("%d",D[ni-1][nj-1]);
           if ( i == pts.size()-1 && cas == tcas-1 ) { }
           else { printf("\n"); }
       }
       printf("\n");
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
