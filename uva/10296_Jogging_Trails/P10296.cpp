/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10296  C++  "Dynamic Programming, Bitmask" */
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

const int MAXN=15, INF=0x3f3f3f3f;
int memo[1<<15], N;
int adj[MAXN+2][MAXN+2], C[MAXN+2][MAXN+2];
int src;

// mask, current city, start city = cost
int rec(int mask) {
   if(mask == (1<<N)-1) return 0;
   if(memo[mask] >= 0) 
      return memo[mask];
   int res = INF;
   for(int i = 0; i < N; ++i) {
      if(mask & (1<<i)) {
         for(int j = 0; j < N; ++j) {
            if(i == j) continue;
            if(!(mask & (1<<j)))
               res = min(res, rec(mask|(1<<j)) + adj[i][j]);
         }
      }
   }
   return memo[mask] = res;
}

int main(int argc, char *argv[]) {
   int M, u, v, dist, res;
   while(2 == scanf("%d%d",&N,&M)) {
      memset(adj,0x3f,sizeof(adj));
      memset(C,0x3f,sizeof(C));
      while(M-- > 0) {
         scanf("%d%d%d",&u,&v,&dist);
         --u; --v;
         C[u][v] = adj[u][v] = dist;
         C[v][u] = adj[v][u] = dist;
      }
      for(int i = 0; i < N; ++i) C[i][i] = 0;
      // DEBUG
      for(int i = 0; i < N; ++i) {
         printf("%d: ",i);
         for(int j = 0; j < N; ++j) {
            printf("%d ",adj[i][j]);
         }
         putchar('\n');
      }
      for(int k = 0; k < N; ++k) {
         for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
               C[i][j] = min(C[i][j],C[i][k]+C[k][j]);
            }
         }
      }
      res = INF;
      for(int i = 0; i < N; ++i) {
         memset(memo,-1,sizeof(memo));
         src = i;
         cout << rec(1<<i) << endl;
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
