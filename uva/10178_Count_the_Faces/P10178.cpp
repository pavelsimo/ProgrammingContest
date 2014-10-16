/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10178  C++  "Disjoint Sets" */
#include <iostream>
#include <map>

using namespace std;

map<string,int> m_id;
int parent[256];

int find_set(int x) {
   if(parent[x] == x) 
      return x;
   return parent[x] = find_set(parent[x]);
}

bool union_set(int x, int y) {
   x = find_set(x);
   y = find_set(y);
   if(x == y) return true; // cycle
   parent[x] = y;
   return false;
}

int main(int argc, char *argv[]) {
   ios_base::sync_with_stdio(false);
   string s, u, v;
   int n, m, p, q, res;
   while(cin >> n >> m) {
      m_id.clear();
      for(int i = 0; i < n; ++i)
         parent[i] = i;
      res = 1;
      for(int i = 0, j = 0; i < m; ++i) {
         cin >> u >> v;
         if(m_id.count(u) == 0) m_id[u] = j++;
         if(m_id.count(v) == 0) m_id[v] = j++;
         p = m_id[u], q = m_id[v];
         if(union_set(p, q)) res++;
      }
      cout << res << '\n';
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
