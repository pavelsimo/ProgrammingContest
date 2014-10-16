#include <cstdio>

#include <vector>
#include <algorithm>

using namespace std;

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
// path compression
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

struct Edge {
// int id;
   int u, v;
   int cost;
   Edge(int _u, int _v, int _cost) : u(_u), v(_v), cost(_cost) {}
// Edge(int _id, int _u, int _v, int _cost)
//   : id(_id), u(_u), v(_v), cost(_cost) {}
};

class CostCmp {
public:
   bool operator()(const Edge& e1, const Edge& e2) {
      if (e1.cost != e2.cost) return e1.cost < e2.cost;
      if (e1.u != e2.u) return e1.u < e2.u;
      return e1.v < e2.v;
   // return e1.id < e2.id;
   }
};

#define MAXN 100004

int N, M;
vector<Edge> edges;
bool prv_conn[MAXN];

int main() {
   scanf("%d %d", &N, &M);
   for (int j = 0; j < M; ++j) {
      int u, v, cost;
      scanf("%d %d %d", &u, &v, &cost);
      edges.push_back(Edge(u, v, cost));
   }

   sort(edges.begin(), edges.end(), CostCmp());

   bool uniq = true;
   DisjointSet dset(N);
   for (int j = 0; j < edges.size(); ) {
      int K = j;
      for (; K < edges.size() && edges[K].cost == edges[j].cost; ++K) {
         int u = edges[K].u, v = edges[K].v;
         if (dset.find_rep(u) == dset.find_rep(v))
            prv_conn[K] = true;
      }
      fprintf(stderr, "K = %d\n", K);
      for (; j < K; ++j) {
         int u = edges[j].u, v = edges[j].v, cost = edges[j].cost;
         fprintf(stderr, "Processing %d %d %d\n", u, v, cost);
         if (!prv_conn[j]) {
            if (!dset.union_rep(u, v))
               uniq = false;
         }
      }
   }

   puts(uniq ? "YES" : "NO");

   return 0;
}
