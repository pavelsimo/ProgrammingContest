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

class DisjointSet {
   size_t _n;
   size_t _size;
public:
   vector<int>    parent;
   vector<size_t> rank;
 
   DisjointSet(size_t n);
   size_t size() const;
   int find_rep(int u);
   bool union_rep(int u, int v);
};
 
DisjointSet::DisjointSet(size_t n) : _n(n), _size(n) {
   parent = vector<int>(_n, -1);
   rank   = vector<size_t>(_n, 0);
}
 
inline size_t DisjointSet::size() const {
   return _size;
}
 
int DisjointSet::find_rep(int u) {
   return parent[u] < 0 ? u : parent[u] = find_rep(parent[u]);
}
 
bool DisjointSet::union_rep(int u, int v) {
   int u_root = find_rep(u);
   int v_root = find_rep(v);
   if (u_root == v_root)
      return false;
   int u_rank = rank[u_root];
   int v_rank = rank[v_root];
   if (u_rank > v_rank)
      parent[v_root] = u_root;
   else {
      parent[u_root] = v_root;
      if (u_rank == v_rank)
         rank[v_root] = rank[u_root] + 1;
   }
   --_size;
   return true;
}

int main() {
   int n, nedges, u, v;
   cin >> n >> nedges;
   DisjointSet dset(n);
   for(int i = 0; i < nedges; ++i) {
      cin >> u >> v;
      printf("%d <--> %d\n",u,v);
      --u; --v;
      dset.union_rep(u, v);
   }
   cout << endl;
   for(int i = 0; i < sz(dset.parent); ++i) {
      printf("%d : %d\n",i + 1,dset.parent[i]);
   }
   /*
   N = 4; // v_left  size
   M = 3; // v_right size
   memset(seen,false,sizeof(seen));
   v_left  = VI(MAXN, -1);
   v_right = VI(MAXN, -1);
   edges[0].push_back(0);
   edges[0].push_back(2);
   edges[1].push_back(1);   
   edges[1].push_back(2);
   edges[2].push_back(2);
   edges[3].push_back(2);
   DEBUG(bipartite_matching());
   */
   return 0;
}


