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
bool seen[1024], seen2[1024];
stack<int> X;
int freq[1024];

void dfs(int cur) {
   for(int i = 0; i < sz(adj[cur]); ++i) {
      int nxt = adj[cur][i];
      if(!seen[nxt]) {
         seen[nxt] = true;
         dfs(nxt);
      }
   }
   X.push(cur);
}

void findpath(int cur, int cost) {
   for(int i = 0; i < sz(adj[cur]); ++i) {
      int nxt = adj[cur][i];
      freq[nxt]++;
      if(!seen[nxt]) {
         seen[nxt] = true;
         findpath(nxt);
         seen[nxt] = false;
      }
   }
}

int main(int argc, char *argv[]) {
   ios_base::sync_with_stdio(0);
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
      printf("Case #%d: ",tc);
      bool found = false;      
      memset(seen, false, sizeof(seen));
      for(int i = 0; i < N; ++i)
         if(!seen[i]) dfs(i);
      memset(seen, false, sizeof(seen));      
      while(!X.empty()) {
         int cur = X.top();
         memset(freq, 0, sizeof(freq));
         findpath(cur);
         for(int i = 0; i < N; ++i) {
            if(freq[i] > 1) found = true;
         }
         X.pop();
      }
      if(found) puts("Yes");
      else puts("No");
   }
   return 0;
}
