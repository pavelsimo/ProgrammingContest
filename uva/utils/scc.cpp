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

const int MAXN = 875714;

set<int> V;
vector<int> adj[MAXN], adj_rev[MAXN], scc_sz(MAXN, 0);
int F[MAXN], L[MAXN], N, S, T = 0;

bool seen[MAXN];

void dfs1(int cur) {
   seen[cur] = true;
   for(int i = 0; i < sz(adj_rev[cur]); ++i) {
      int nxt = adj_rev[cur][i];
      if(!seen[nxt])
         dfs1(nxt);
   }
   F[T++] = cur;
}

void dfs2(int cur) {
   seen[cur] = true;
   L[cur] = S;
   for(int i = 0; i < sz(adj[cur]); ++i) {
      int nxt = adj[cur][i];
      if(!seen[nxt])
         dfs2(nxt);
   }
}

int main(int argc, char *argv[]) {
   ios_base::sync_with_stdio(0);
   int u, v;
   string s;
   while(getline(cin,s)) {
      istringstream in(s);
      in >> u;
      --u;
      V.insert(u);
      while(in >> v) {
         --v;
         V.insert(v);
         adj[u].push_back(v);
         adj_rev[v].push_back(u);
      }      
   }
   memset(seen, false, sizeof(seen));
   T = 0;
   for(int i = 0; i < MAXN; ++i) {
      if(!seen[i])
         dfs1(i);
   }
   memset(seen, false, sizeof(seen));
   for(int i = MAXN - 1; i >= 0; --i) {
      int cur = F[i];
      if(!seen[cur]) {
         S = cur;  
         dfs2(cur);
      }
   }
   foreach(it,V) scc_sz[L[*it]]++;
   sort(scc_sz.rbegin(), scc_sz.rend());
   for(int i = 0; i < 5; ++i) {
      if(i > 0) putchar(',');
      printf("%d",scc_sz[i]);
   }
   printf("\n");
   return 0;
}
// END CUT HERE
