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


const int MAXN = 60002;
vector<int> adj[MAXN];
int P[MAXN];
bool seen[MAXN];

void dfs(int cur) {
   if(!seen[cur]) {
      seen[cur] = true;
      for(int i = 0; i < sz(adj[cur]); ++i) {
         int nxt = adj[cur][i];
         dfs(nxt);
         P[nxt] = cur;
      }
   }
}

int main(int argc, char *argv[]) {	
   int n, r1, r2, u;
   cin >> n >> r1 >> r2;
   --r1; --r2;
   for(int v = 0; v < n; ++v) {
      if(v == r1) continue;
      cin >> u;
      --u;
      adj[u].push_back(v);
      adj[v].push_back(u);                        
   }
   memset(seen, false, sizeof(seen));
   dfs(r2);
   for(int v = 0; v < n; ++v) {
      if(v == r2) continue;
      cout << P[v] + 1 << ' ';
   }
   cout << endl;
   return 0;
}

