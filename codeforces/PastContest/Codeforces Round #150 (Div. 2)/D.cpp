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

typedef pair<int,int> ii;
typedef vector<int> VI;
typedef vector<VI> VII;
typedef vector<ii> VPII;

int N, M, id;
VII adj;
VI num, low, prev;
VPII edges;

// Bridges
void dfs(int cur) {
	num[cur]=low[cur]=++id;
	for(int i = 0; i < adj[cur].size(); ++i) {
		int nxt = adj[cur][i];
		if(!num[nxt]) {
			prev[nxt] = cur;
			dfs(nxt);
			if(low[nxt] > num[cur]) 
				edges.push_back(ii(min(cur,nxt),max(cur,nxt)));
			low[cur] = min(low[cur],low[nxt]);
		} else {
			if(prev[cur]!=nxt)
				low[cur] = min(low[cur],num[nxt]);
		}
	}
}

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n, m, h, t, u, v;
   cin >> n >> m >> h >> t;
   adj  = VII(n + 1);
   low  = VI(n + 1);
   num  = VI(n + 1);
   prev = VI(n + 1);
   for(int i = 0; i < m; ++i) {
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
   }
   for(int i = 0; i < n; ++i)
      if(!num[i])
         dfs(i);
   sort(edges.begin(),edges.end());
   printf("%d critical links\n",edges.size());
   for(int i = 0; i < edges.size(); ++i)
      printf("%d - %d\n",edges[i].first,edges[i].second);
   return 0;
}

