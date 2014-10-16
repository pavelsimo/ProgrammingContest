/*
ID: 6
PROG: cornmaze
LANG: C++
*/
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

typedef long long llong;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> ii;

#define DEBUG(x) cout << #x << ": " << x << endl
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define sz(a) int((a).size())

int N, M;
const int MAXN = 310;
char B[MAXN][MAXN];
int D[MAXN][MAXN];
int dr[4] = {+1,-1,+0,+0}, dc[4] = {+0,+0,+1,-1};
vector<ii> portal[256];

int bfs(ii src) {
   memset(D,-1,sizeof(D));
   queue<ii> Q;
   Q.push(src);
   D[src.first][src.second] = 0;
   while(!Q.empty()) {
      ii cur = Q.front(); Q.pop();
      int r = cur.first;
      int c = cur.second;
      if(B[r][c]=='=') 
         return D[r][c];
      for(int d = 0; d < 4; ++d) {
         int nr = r + dr[d];
         int nc = c + dc[d];
         if(nr < 0 || nr >= N || nc < 0 || nc >= M || B[nr][nc]=='#') continue;
         if(B[nr][nc] >= 'A' && B[nr][nc] <= 'Z') {
            ii teleport;
            if(make_pair(nr,nc)==portal[int(B[nr][nc])][0]) 
               teleport = portal[int(B[nr][nc])][1];
            else 
               teleport = portal[int(B[nr][nc])][0];
            if(D[teleport.first][teleport.second]<0) {
               D[teleport.first][teleport.second] = D[r][c]+1;
               Q.push(teleport);
            }
         } else {
            if(D[nr][nc] < 0) {
               D[nr][nc] = D[r][c]+1;
               Q.push(ii(nr,nc));
            }            
         }
      }
   }
   return -1;
}

int main() {
   freopen("cornmaze.in", "r", stdin);
   freopen("cornmaze.out", "w", stdout);
   ii src;
   scanf("%d%d",&N,&M);
   for(int i = 0; i < N; ++i)
      scanf("%s",B[i]);
   for(int i = 0; i < N; ++i) {
      for(int j = 0; j < M; ++j) {
         if(B[i][j]=='@') 
            src = make_pair(i,j);
         if(B[i][j]>='A' && B[i][j]<='Z')
            portal[int(B[i][j])].push_back(make_pair(i,j));
      }
   }
   printf("%d\n",bfs(src));
   return 0;
}
