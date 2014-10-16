/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11470  C++  "Graph Theory" */
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

int N;
const int MAXN = 12;
bool seen[MAXN][MAXN];
int A[MAXN][MAXN];
int dr[] = {+0,+1,+0,-1};
int dc[] = {+1,+0,-1,+0};

int calc(int r, int c) {
   int res = A[r][c];
   seen[r][c] = true;
   for(int dir = 0; dir < 4; ++dir) {
      while(true) {
         int nr = r + dr[dir];
         int nc = c + dc[dir];
         if(nr < 0 || nr >= N || nc < 0 || nc >= N || seen[nr][nc]) break;
         r = nr;
         c = nc;
         seen[r][c] = true;
         res+=A[r][c];
      }
   }
   return res;
}

int main(int argc, char *argv[]) {
   for(int tc = 1; scanf("%d",&N)==1 ; ++tc) {
      if(N==0) break;
      for(int i = 0; i < N; ++i) {
         for(int j = 0; j < N; ++j) {
            scanf("%d",&A[i][j]);
         }
      }      
      memset(seen,false,sizeof(seen));
      int M = ceil(N/2.0);
      printf("Case %d: ",tc);
      for(int i = 0; i < M; ++i) {
         if(i > 0) putchar(' ');
         printf("%d",calc(i,i));
      }
      putchar('\n');
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
