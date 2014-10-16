/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10305  C++  "Graph Theory, Topological Sorting" */
#include <iostream>
#include <cstring> 
#include <algorithm>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <cmath>
#include <complex>
#include <stack>
#include <list>
using namespace std;

typedef vector<int> vi;

const int maxn = 102;
int in_degree[maxn];
vi adj[maxn];
bool vis[maxn];
stack<int> L;

// topological sort
void visit(int u) {
   if(!vis[u]) {
      vis[u] = true;
      for(int i = 0; i < adj[u].size(); ++i) {
         int v = adj[u][i];
         visit(v);
      }
      L.push(u);
   }
}

int main(int argc, char *argv[]) {
   int N, M, u, v;
   while(scanf("%d%d",&N,&M)==2) {
      if(N==0 && M==0) break;
      memset(in_degree,0,sizeof(in_degree));
      memset(vis,false,sizeof(vis));
      for(int i = 0; i <= N; ++i)
         adj[i].clear();
      for(int i = 0; i < M; ++i) {
         scanf("%d%d",&u,&v);
         adj[u].push_back(v);
         in_degree[v]++;
      }
      for(int i = 1; i <= N; ++i) {
         if(in_degree[i]==0)
            visit(i);
      }     
      for(int j = 0; !L.empty(); ++j) {
         if(j>0) putchar(' ');
         printf("%d",L.top());
         L.pop();
      }
      putchar('\n');
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
