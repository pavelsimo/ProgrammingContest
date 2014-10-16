/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  280  C++  "Graph Theory, DFS" */
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

typedef vector<int> VI;

bool seen[102];
VI adj[102];

void dfs(int cur) {
   for(int i = 0; i < sz(adj[cur]); ++i) {
      int nxt = adj[cur][i];
      if(!seen[nxt]) {
         seen[nxt] = true;
         dfs(nxt);
      }
   }
}

int main(int argc, char *argv[]) {
   int N, u, v, q, src, cnt;
   while(scanf("%d",&N)==1) {
      if(N==0) break;
      for(int i = 1; i <= N; ++i) adj[i].clear();
      while(scanf("%d",&u)==1) {
         if(u==0) break;
         while(scanf("%d",&v)==1) {
            if(v==0) break;
            adj[u].push_back(v);  
         }
      }
      scanf("%d",&q);
      while(q-- > 0) {
         memset(seen,false,sizeof(seen));
         scanf("%d",&src);
         cnt = 0;
         dfs(src);
         for(int i = 1; i <= N; ++i) 
            if(!seen[i]) cnt++;
         printf("%d",cnt);
         for(int i = 1; i <= N; ++i)
            if(!seen[i]) printf(" %d",i);
         putchar('\n');
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
