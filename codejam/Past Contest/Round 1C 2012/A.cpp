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

int N, M;
vector<int> adj[1024];
bool seen[1024];
bool found;

void dfs(int cur) {
   for(int i = 0; i < sz(adj[cur]); ++i) {
      int nxt = adj[cur][i];
      if(!seen[nxt]) {
         seen[nxt] = true;
         dfs(nxt);
      } else {
         found = true;
      }
   }
}

int main(int argc, char *argv[]) {
   int TC, u;
   scanf("%d",&TC);
   for(int tc = 1; tc <= TC; ++tc) {
      scanf("%d",&N);
      for(int i = 0; i <= N; ++i)
         adj[i].clear();
      for(int i = 0; i < N; ++i) {
         scanf("%d",&M);
         for(int j = 0; j < M; ++j) {
            scanf("%d",&u);
            --u;     
            adj[i].push_back(u);
         }
      }
      found = false;
      for(int i = 0; i < N; ++i) {
         memset(seen, false, sizeof(seen));
         dfs(i);
         if(found) break;
      }
      printf("Case #%d: %s\n",tc,found?"Yes":"No");
   }
   return 0;
}
