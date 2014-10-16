/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11561  C++  "Graph Theory, DFS, flood fill" */
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

int N, M, res;
int dr[] = {+1,+0,-1,+0};
int dc[] = {+0,+1,+0,-1};

char B[55][55];
void dfs(int i, int j) {
   if(i < 0 || i >= N || j < 0 || j >= M || B[i][j]=='T' || B[i][j]=='#') return;
   if(B[i][j]=='G') res++;
   B[i][j] = '#';
   bool ok = true;
   for(int dir = 0; dir < 4; ++dir) {
      int nr = i + dr[dir];
      int nc = j + dc[dir];
      if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
      if(B[nr][nc]=='T') {
         ok = false;
         break;
      }
   }
   if(ok) {
      for(int dir = 0; dir < 4; ++dir)
         dfs(i + dr[dir], j + dc[dir]);
   }
}

int main(int argc, char *argv[]) {
   int rsrc, csrc;
   while(scanf("%d%d",&M,&N)==2) {
      for(int i = 0; i < N; ++i) {
         scanf("%s",B[i]);
         for(int j = 0; j < M; ++j) {
            if(B[i][j]=='P') {
               rsrc = i;
               csrc = j;
            }
         }
      }
      res = 0;
      dfs(rsrc,csrc);
      printf("%d\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
