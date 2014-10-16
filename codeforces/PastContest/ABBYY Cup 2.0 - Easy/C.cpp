#include <iostream>

using namespace std;

typedef long long llong;

int parent[2002], size[2002];

int find_set(int x) {
   if(x != parent[x]) parent[x] = find_set(parent[x]);
   return parent[x];
}

void union_set(int x, int y) {
   x = find_set(x); y = find_set(y);
   parent[x] = y;
}

int main(int argc, char *argv[]) {
   int n, k, m, u, v, res;
   cin >> n >> k;
   for(int i = 0; i < n; ++i)
      parent[i] = i, size[i] = 0;
   for(int i = 0; i < k; ++i) {
      cin >> u >> v;
      --u; --v;
      union_set(u, v);
   }
   for(int i = 0; i < n; ++i)
      size[find_set(i)]++;
   cin >> m;
   for(int i = 0; i < m; ++i) {
      cin >> u >> v;
      --u; --v;
      u = find_set(u); v = find_set(v);
      if(u == v) size[u] = -1;
   }
   res = 0;
   for(int i = 0; i < n; ++i)
      res = max(res, size[i]);
   cout << res << endl;
   return 0;
}

