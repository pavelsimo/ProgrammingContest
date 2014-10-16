/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10685  C++  "Disjoint Sets" */
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

map<string,int> m_id;
int parent[5002], size[5002];

int find_set(int x) {
   if(parent[x] == x) 
      return x;
   return parent[x] = find_set(parent[x]);
}

void union_set(int x, int y) {
   x = find_set(x);
   y = find_set(y);
   if(x == y) return;
   parent[x] = y;
   size[y] += size[x];
}

int main(int argc, char *argv[]) {
   ios_base::sync_with_stdio(false);
   string s, u, v;
   int n, m, res;
   while(cin >> n >> m) {
      m_id.clear();
      if(!n && !m) break;
      for(int i = 0; i < n; ++i) {
         cin >> s;
         m_id[s] = i;
         parent[i] = i;
         size[i] = 1;
      }
      for(int i = 0; i < m; ++i) {
         cin >> u >> v;
         union_set(m_id[u], m_id[v]);
      }
      res = 0;
      for(int i = 0; i < n; ++i)
         res = max(res, size[i]);
      cout << res << '\n';
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
