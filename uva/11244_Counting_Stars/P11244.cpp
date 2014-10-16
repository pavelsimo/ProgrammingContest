/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11244  C++  "Graph Theory" */
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

const int MAXN = 110;
int N, M;
int dr[] = {+1,+0,-1,+0,+1,+1,-1,-1};
int dc[] = {+0,+1,+0,-1,+1,-1,+1,-1};
char B[MAXN][MAXN];

bool check(int r, int c) {
   for(int dir = 0; dir < 8; ++dir) {
      int nr = r + dr[dir];
      int nc = c + dc[dir];
      if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
      if(B[nr][nc]=='*') return false;
   }
   return true;
}

int main(int argc, char *argv[]) {
   int res;
   while(scanf("%d%d",&N,&M)==2) {
      if(N==0 && M==0) break;
      for(int i = 0; i < N; ++i)
         scanf("%s",B[i]);
      res = 0;
      for(int i = 0; i < N; ++i) {
         for(int j = 0; j < M; ++j)
            if(B[i][j]=='*' && check(i,j))
               res++;
      }
      printf("%d\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
