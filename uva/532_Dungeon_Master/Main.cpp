/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  15240 532  C++  "Graph BFS" */
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
typedef vector<int> VI;
typedef vector<string> VS;
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

struct point {
    int x;
    int y;
    int z;
};

int D[31][31][31];
int dx[] = {1,-1,0,0,0,0};
int dy[] = {0,0,1,-1,0,0};
int dz[] = {0,0,0,0,1,-1};

int bfs(char v[][31][31], int n, int m, int r) {

  point start;
  queue<point> q;

  for (int z = 0; z < 31; ++z) {
      for (int x = 0; x < 31; ++x) {
          for (int y = 0; y < 31; ++y) {
              D[x][y][z] = -1;
          }
      }
  }

  for (int z = 0; z < r; ++z) {
      for (int x = 0; x < n; ++x) {
          for (int y = 0; y < m; ++y) {
              if ( v[x][y][z] == 'S' ) {
                  start.x = x;
                  start.y = y;
                  start.z = z;
              }
          }
      }
  }

  q.push(start);
  D[start.x][start.y][start.z] = 0;

  while ( !q.empty() ) {
      point s = q.front();
      q.pop();
      if ( v[s.x][s.y][s.z] == 'E' )
          return D[s.x][s.y][s.z];
      for(int i = 0; i < 6; ++i) {
          int nx = s.x+dx[i];
          int ny = s.y+dy[i];
          int nz = s.z+dz[i];
          if ( nx >= 0 && nx < n && ny >= 0 && ny < m && nz >= 0 && nz < r 
                && (v[nx][ny][nz] == '.' || v[nx][ny][nz] == 'E') && D[nx][ny][nz] == -1 ) {
              D[nx][ny][nz] = D[s.x][s.y][s.z] + 1;
              point np;
              np.x = nx;
              np.y = ny;
              np.z = nz;
              q.push(np);
          }
      }
  }
  return -1; 
}

int main() {
  char v[31][31][31];
  int r, n, m;
  while ( cin >> r >> n >> m  ) {
    if ( r == 0 && n == 0 && m == 0 ) break;
    for (int z = 0; z < r; ++z)
        for (int x = 0; x < n; ++x)
            for (int y = 0; y < m; ++y)
                cin >> v[x][y][z];
    int res = bfs(v,n,m,r);
    if ( res != -1 )
      printf("Escaped in %d minute(s).\n", res);
    else
      printf("Trapped!\n");
  }
  return 0;
}


/* @END_OF_SOURCE_CODE */
