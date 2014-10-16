/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  15240 439  C++  "Graph BFS" */
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

int dx[] = {-2, -2, 2, 2, -1, 1, -1, 1};
int dy[] = {-1, 1, -1, 1, -2, -2, 2, 2};
int v[8][8];

struct point {
    int x;
    int y;
};

int bfs(int x, int y, int tx, int ty) {
  int n = 8;
  for (int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
        v[i][j] = -1;

  queue<point> q;
  point start;
  start.x = x;
  start.y = y;   
  q.push(start);
  v[x][y] = 0;
  while ( !q.empty() ) {
      point s = q.front();
      q.pop();
      if ( s.x == tx && s.y == ty ) 
          return v[tx][ty];
      for(int i = 0; i < n; ++i) {
          int nx = s.x + dx[i];
          int ny = s.y + dy[i];
          if ( nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && v[nx][ny] == -1 ) {   
              point np;
              np.x = nx;
              np.y = ny;
              v[nx][ny] = v[s.x][s.y]+1;              
              q.push(np);
          }
      } 
  }
  return 0; 
}

int main() {
    string s;
    while ( getline(cin,s)  ) {
        int x  = s[0]-'a';
        int y  = s[1]-'1';
        int tx = s[3]-'a';
        int ty = s[4]-'1';
        printf("To get from %c%c to %c%c takes %d knight moves.\n",s[0],s[1],s[3],s[4],bfs(x,y,tx,ty));
    }
    return 0;
}


/* @END_OF_SOURCE_CODE */
