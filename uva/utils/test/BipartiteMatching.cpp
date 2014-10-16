#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<cmath>

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())

using namespace std;
typedef vector<int> VI;

const int MAXN = 30;
VI v_left, v_right, edges[MAXN];
bool seen[MAXN];
int N, M;

bool dfs(int cur) {
   if(seen[cur]) return false;
   seen[cur] = true;
   for(int v = 0; v < sz(edges[cur]); ++v) {
      int nxt = edges[cur][v];
      if(v_right[nxt]==-1 || dfs(v_right[nxt])) {
         v_left[cur] = nxt;
         v_right[nxt] = cur;
         return true;
      } 
   }
   return false;
}

int bipartite_matching() {
   int res = 0;
   bool aug_path_found;
   while(true) {
      memset(seen,false,sizeof(seen));
      aug_path_found = false;
      for(int i = 0; i < N; ++i) {
          if(v_left[i] == -1 && dfs(i))
             aug_path_found = true;
      }
      if(!aug_path_found) break;
   }
   for(int i = 0; i < N; ++i) {
      if(v_left[i]!=-1)
         res++;
   }
   return res;
}

int main() {
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
   return 0;
}
