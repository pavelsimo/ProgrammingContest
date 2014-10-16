/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ LABYR1 C++ "Graph Theory, Longest Path" */
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

typedef pair<int,int> ii;

const int MAXN = 1024;
int N, M, D[MAXN][MAXN], br, bc;
char B[MAXN][MAXN];
int dr[] = {+1,+0,-1,+0};
int dc[] = {+0,+1,+0,-1};

int bfs(int sr, int sc) {
   memset(D,-1,sizeof(D));
   queue<ii> Q;
   int res = 0;
   Q.push(ii(sr,sc));
   D[sr][sc] = 0;
   br = sr;
   bc = sc;
   while(!Q.empty()) {
      ii cur = Q.front(); Q.pop();
      int cr = cur.first;
      int cc = cur.second;
      if(D[cr][cc] > res) {
         res = D[cr][cc];
         br = cr;
         bc = cc;
      }
      for(int d = 0; d < 4; ++d) {
         int nr = cr + dr[d];
         int nc = cc + dc[d];
         if(nr >= N || nr < 0 || nc >= M || nc < 0 || B[nr][nc]!='.') continue;
         if(D[nr][nc] < 0) {
            D[nr][nc] = D[cr][cc] + 1;
            Q.push(ii(nr,nc));
         }
      }
   }
   return res;
}

int main(int argc, char *argv[]) {
   int TC, rs, cs, res;
   bool found;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d%d",&M,&N);
      for(int i = 0; i < N; ++i)
         scanf("%s",B[i]);
      found = false;
      for(int r = 0; r < N; ++r) {
         for(int c = 0; c < M; ++c) {
            if(B[r][c]=='.') {
               rs = r;
               cs = c;
               found = true;
               break;
            }
         }
         if(found) break;
      }
      bfs(rs,cs);
      res = bfs(br,bc);
      printf("Maximum rope length is %d.\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
