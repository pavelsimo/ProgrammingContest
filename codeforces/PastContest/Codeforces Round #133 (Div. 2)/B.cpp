#include <iostream>

using namespace std;

int parent[102], size[102];

int find_set(int x) {
   if(x == parent[x]) 
      return x;
   return parent[x] = find_set(parent[x]);
}

bool union_set(int x, int y) {
   x = find_set(x);
   y = find_set(y);
   if(x == y) // cycle
      return false;
   parent[x] = y;
   size[y] += size[x];
   return true;
}

int main(int argc, char *argv[]) {
   ios_base::sync_with_stdio(false);   
   int n, m, u, v, res;
   cin >> n >> m; 
   for(int i = 0; i < n; ++i) {
      parent[i] = i;
      size[i] = 1;
   }
   res = 0;
   for(int i = 0; i < m; ++i) {
      cin >> u >> v;
      --u; --v;
      if(!union_set(u, v)) {
         if(size[find_set(u)] & 1) 
            res++;
      }
   }
   if((n - res) & 1) ++res;
   cout << res << endl;
   return 0;
}
