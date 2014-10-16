/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ MLASERP C++ "BFS, Graph Theory" */
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <deque>
#include <numeric>
#include <iterator>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <climits>
#include <sys/time.h>
#include <regex.h>
 
using namespace std;
 
#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
 
const int MAXN = 110, INF = 100000000;
int N, M, xsrc, ysrc, xdst, ydst, D[MAXN][MAXN];
char B[MAXN][MAXN];
bool seen[MAXN][MAXN][10];
int dx[] = {+1,-1,+0,+0};
int dy[] = {+0,+0,+1,-1};
 
struct Node {
  int x;
  int y;
  int cost;
  int dir;
  int mirror;
  Node(int _x, int _y, int _cost, int _dir, int _mirror) : 
   x(_x), y(_y), cost(_cost), dir(_dir), mirror(_mirror) {}
  bool operator <(const Node &T) const {
     if(mirror!= T.mirror) return T.mirror < mirror;
     if(cost!=T.cost) return T.cost < cost;
     return false;
  }
};
 
int bfs() {
   memset(seen,false,sizeof(seen));
   priority_queue<Node> Q;
   Q.push(Node(xsrc,ysrc,0,0,0));
   int cnt = 0;
   while(!Q.empty()) {
      Node cur = Q.top();
      int cx = cur.x;
      int cy = cur.y;
      Q.pop();
      if(seen[cx][cy][cur.dir]) continue;
      seen[cx][cy][cur.dir] = true;
      if(cx==xdst && cy==ydst)
         return cur.mirror;
      for(int d = 0; d < 4; ++d) {
         int nx = cx + dx[d];
         int ny = cy + dy[d];
         if(nx < 0 || ny < 0 || nx >= N || ny >= M || B[nx][ny]=='*') continue;
         int c = (cur.dir==d) ? cur.mirror: cur.mirror + 1;
         if(cnt==0)c=0;
         Node nxt(nx,ny,cur.cost+1,d,c);
         Q.push(nxt);
      }
      cnt++;
   }
   return -1;
}
 
int main(int argc, char *argv[]) {
   while(scanf("%d%d",&M,&N)==2) {
      xsrc = ysrc = xdst = ydst = -1;
      for(int i = 0; i < N; ++i) {
         scanf("%s",B[i]);
         for(int j = 0; j < M; ++j) {
            if(B[i][j]=='C') {
               if(xsrc < 0) {
                  xsrc = i;
                  ysrc = j;
               } else {
                  xdst = i;
                  ydst = j;
               }
            }
         }
      }
      printf("%d\n",bfs());
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
