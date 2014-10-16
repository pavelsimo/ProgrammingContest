/* @JUDGE_ID: 1131EP  11733  C++  "Kruskal" */
#include <cstdio>

#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
   int u, v, cost;
   Edge(int _u, int _v, int _cost) : u(_u), v(_v), cost(_cost) {}
   bool operator<(const Edge& e) const {
      if (cost != e.cost) return cost < e.cost;
      if (u != e.u) return u < e.u;
      return v < e.v;
   }
};

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

DisjointSet::DisjointSet(size_t n)
   : _n(n), _size(n), parent(n, -1), rank(n, 0) {}

inline size_t DisjointSet::size() const {
   return _size;
}

int DisjointSet::find_rep(int u) {
// path compression
   return parent[u] < 0 ? u : parent[u] = find_rep(parent[u]);
/*
   vector<int> s;
   while (parent[u] >= 0) {
      s.push_back(u);
      u = parent[u];
   }
   for (int i = 0; i < s.size(); ++i)
      parent[s[i]] = u;
   return u;
*/
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

int main(int argc, char* argv[]) {
   int TC;
   scanf("%d", &TC);
   for (int tc = 1; tc <= TC; ++tc) {
      int N, M, A;
      scanf("%d %d %d", &N, &M, &A);
      vector<Edge> edges;
      while (M-- > 0) {
         int u, v, cost;
         scanf("%d %d %d", &u, &v, &cost);
         --u, --v;
         edges.push_back(Edge(u, v, cost));
      }
      sort(edges.begin(), edges.end());
      int res = 0;
      DisjointSet dset(N);
      for (int j = 0; j < edges.size() && dset.size() > 1; ++j) {
      // printf("%d %d %d\n", edges[j].u, edges[j].v, edges[j].cost);
         if (edges[j].cost >= A) break;
         if (dset.union_rep(edges[j].u, edges[j].v))
            res += edges[j].cost;
      }
      res += A * dset.size();
      printf("Case #%d: %d %d\n", tc, res, (int) dset.size());
   }
   return 0;
}
