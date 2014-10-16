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

const int MAXN = 22;
int n, m, spath, res, adj[MAXN][MAXN], C[MAXN][MAXN];
bool seen[MAXN];

void count(int cur, int cost) {
   if(cost > spath) return;
   if(cur == n - 1 && cost == spath) {
      res++;
      return;
   }
   for(int nxt = 0; nxt < n; ++nxt) {
      if(nxt == cur) continue;
      if(C[cur][nxt] != -1) {
         seen[nxt] = true;
         count(nxt, cost + C[cur][nxt]);
         seen[nxt] = false;
      }
   }
}

int main() { 
   int TC, ai, bi, ci;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d%d",&n,&m);
      memset(C, -1, sizeof(C));
      memset(adj, 0x3f, sizeof(adj));
      memset(seen, false, sizeof(seen));
      res = 0;
      for(int i = 0; i < m; ++i) {
         scanf("%d%d%d",&ai,&bi,&ci);
         --ai; --bi;
         C[ai][bi] = adj[ai][bi] = ci;
         C[bi][ai] = adj[bi][ai] = ci;
      }
      for(int k = 0; k < n; ++k) {
         for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {   
               if(adj[i][k] + adj[k][j] < adj[i][j]) {
                  adj[i][j] = adj[i][k] + adj[k][j];
               }
            }            
         }         
      }
      spath = adj[0][n-1];
      seen[0] = true;
      count(0, 0);
      printf("%d\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
