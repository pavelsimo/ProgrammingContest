/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12114  C++  "Graph Theory, Shortest Path, Floyd and Warshall" */
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

const int MAXN = 102, INF = 0x3f3f3f3f;
int adj[MAXN][MAXN];

int main(int argc, char *argv[]) {
   int TC, N, E, T, M, u, v, dist, res;
   scanf("%d",&TC);
   for(int tc = 0; tc < TC; ++tc) {
      if(tc > 0) putchar('\n');
      scanf("%d%d%d%d",&N,&E,&T,&M);
      memset(adj,0x3f,sizeof(adj));
      for(int i = 0; i < N; ++i)
         adj[i][i] = 0;
      for(int i = 0; i < M; ++i) {
         scanf("%d%d%d",&u,&v,&dist);
         --u; --v;
         adj[u][v] = dist;
      }
      for(int k = 0; k < N; ++k) {
         for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
               adj[i][j] = min(adj[i][j],adj[i][k]+adj[k][j]);
            }
         }
      }
      res = 0;
      for(int i = 0; i < N; ++i)
         if(adj[i][E - 1] <= T) res++;
      printf("%d\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
