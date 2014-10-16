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

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

typedef pair<int,int> Point;
const int MAXN = 1002, INF = 0x3f3f3f3f;
int B[MAXN][MAXN], N, src, dst, u, v;
int hay[MAXN][MAXN];
int dr[] = {+1,-1,+0,+0};
int dc[] = {+0,+0,+1,-1};

void print_board() {
   for(int i = 1; i <= 5; ++i) {
      for(int j = 1; j <= 5; ++j) {
         if(hay[i - 1][j - 1] && B[i - 1][j - 1] == INF) printf("X ");
         else printf("%c ",B[i - 1][j - 1] == INF ? '_' : B[i - 1][j - 1] + '0');
      }
      putchar('\n');
   }
   putchar('\n');
}

void bfs() {
   queue<Point> Q;
   Q.push(make_pair(src, dst));
   B[src][dst] = 0;
   while(!Q.empty()) {
      Point cur = Q.front();
      Q.pop();
      print_board();
      for(int i = 0; i < 4; ++i) {
         int nr = cur.first  + dr[i];
         int nc = cur.second + dc[i];
         if(nr >= 1000 || nr < 0 || nc >= 1000 || nc < 0) continue;
         if(B[nr][nc] == INF) {
            B[nr][nc] = B[cur.first][cur.second] + hay[nr][nc];
            Q.push(make_pair(nr,nc));
         } else {
            B[nr][nc] = min(B[nr][nc], B[cur.first][cur.second]);
         }
      }
   }
}

int main() {
   //freopen("tractor.in", "r", stdin);
   //freopen("tractor.out", "w", stdout);
   memset(hay, 0, sizeof(hay));
   memset(B, 0x3f, sizeof(B));
   scanf("%d%d%d",&N, &src, &dst);
   --src, --dst;
   for(int i = 0; i < N; ++i) {
      scanf("%d%d",&u,&v);
      --u; --v;
      hay[u][v] = 1;
   }
   bfs();
   printf("%d\n",B[0][0]);
   return 0;
}
