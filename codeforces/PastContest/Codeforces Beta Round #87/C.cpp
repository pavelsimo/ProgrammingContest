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
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

vector<int> adj[2010];
int depth[2010];

void dfs(int n) {
   for(int i = 0; i < sz(adj[n]); ++i) {
      int nxt = adj[n][i];
      if(depth[nxt] == -1) {
         depth[nxt] = depth[n] + 1;
         dfs(nxt);
      }
   }
}

int main(int argc, char *argv[]) {
   int n, u, v;
   set<int> group;
   memset(depth,-1,sizeof(depth));
   cin >> n;
   for(u = 1; u <= n; ++u) {
      cin >> v;
      if(v < 0) depth[u] = 0;
      else adj[v].push_back(u);   
   }
   for(int i = 1; i <= n; ++i) {
      if(depth[i] == 0) 
         dfs(i);
   }
   for(int i = 1; i <= n; ++i)
      group.insert(depth[i]);
   cout << sz(group) << endl;
   return 0;
}

