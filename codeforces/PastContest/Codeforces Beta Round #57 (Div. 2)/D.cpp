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

typedef long long llong;

const int MAXN = 100002;

vector<pair<int,int> > adj[MAXN];
bool seen[MAXN];

typedef long long llong;

llong dfs(int cur) {
   llong res = 0;
   seen[cur] = true;
   for(int i = 0; i < sz(adj[cur]); ++i) { 
      int nxt = adj[cur][i].first;
      int cost = adj[cur][i].second;
      if(!seen[nxt])
         res = max(res, dfs(nxt) + cost);
   }
   return res;
}

int main(int argc, char *argv[]) {
   int N, u, v, cost;
   llong sum = 0LL;
   cin >> N;
   for(int i = 0; i < N - 1; ++i) {
      cin >> u >> v >> cost;
      sum += cost;
      --u; --v;
      adj[u].push_back(make_pair(v,cost));
      adj[v].push_back(make_pair(u,cost));
   } 
   cout << 2LL * sum - dfs(0) << endl;
   return 0;
}

 
