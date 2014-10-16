/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  610  C++  "Graph Theory, DFS, Bridge" */
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
#include <bitset>
#include <utility>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef set<ii> SII;
int N, M, id;
VI num, low, prev;
VVI adj;
SII vis;
stack<ii> out;


void dfs(int cur) {
   num[cur]=low[cur]=++id;
   for(int i = 0; i < adj[cur].size(); ++i) {
      int nxt = adj[cur][i];
      if(!num[nxt]) {
         prev[nxt] = cur;
         dfs(nxt);
         if(low[nxt] > num[cur]) {
            if(vis.count(ii(cur,nxt))==0) {
               vis.insert(ii(cur,nxt));
               vis.insert(ii(nxt,cur));
               out.push(ii(cur,nxt));
               out.push(ii(nxt,cur));
            }
         } else {
            if(vis.count(ii(cur,nxt))==0) {
               vis.insert(ii(cur,nxt));
               vis.insert(ii(nxt,cur));
               out.push(ii(cur,nxt));
            }
         }
         low[cur] = min(low[cur],low[nxt]);
      } else {
         if(prev[cur]!=nxt) {
            low[cur] = min(low[cur],num[nxt]);
            if(vis.count(ii(cur,nxt))==0) {
               vis.insert(ii(cur,nxt));
               vis.insert(ii(nxt,cur));
               out.push(ii(cur,nxt));
            }
         }
            
      }
   }
}

int main(int argc, char *argv[]) {
   int TC=0, u, v;
   while(2==scanf("%d%d",&N,&M)) {
      if(N==0 && M==0) break;
      adj = VVI(N+1);
      num = VI(N+1);
      low = VI(N+1);
      prev = VI(N+1);
      vis.clear();
      for(int i = 0; i < M; ++i) {
         scanf("%d%d",&u,&v);
         adj[u].push_back(v);
         adj[v].push_back(u);
      }
      id=0;
      for(int i = 1; i <= N; ++i) {
         if(!num[i])
            dfs(i);
      }
      printf("%d\n\n",++TC);
      while(!out.empty()) {
         ii cur = out.top();
         out.pop();
         printf("%d %d\n",cur.first,cur.second);
      }
      puts("#");
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

