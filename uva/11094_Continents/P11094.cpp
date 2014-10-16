/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11094  C++  "Graph Theory, DFS" */
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

const int MAXN = 30;
char B[MAXN][MAXN];
int M, N, cnt;
char land;
int dx[] = {+1,-1,+0,+0};
int dy[] = {+0,+0,+1,-1};

void dfs(int i, int j) {
   if(i < 0 || i >= M || B[i][j] != land) return;
   B[i][j] = '\0';
   cnt++;
   for(int dir = 0; dir < 4; ++dir)
      dfs(i + dx[dir], (N+j+dy[dir])%N);
}

int main(int argc, char *argv[]) {
   int x, y;
   while(scanf("%d%d",&M,&N)==2) {
      for(int i = 0; i < M; ++i)
         scanf("%s",B[i]);
      scanf("%d%d",&x,&y);
      land = B[x][y];
      dfs(x,y);
      int res = 0;
      for(int i = 0; i < M; ++i) {
         for(int j = 0; j < N; ++j) {
            if(B[i][j]==land) {
               cnt = 0;
               dfs(i,j);
               res = max(res,cnt);
            }
         }
      }
      printf("%d\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
