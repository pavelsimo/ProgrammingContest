/*
ID: 12
PROG: pathfind
LANG: C++
*/
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
#include <regex.h>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define pb push_back

int N;
const int maxn = 110;
bool adj[maxn][maxn];
int D[maxn];

void bfs(int src) {
   queue<int> Q;
   D[src] = 0;
   Q.push(src);
   while(!Q.empty()) {
      int cur = Q.front();
      Q.pop();
      for(int nxt = 1; nxt <= N; ++nxt) {
         if(adj[cur][nxt] && D[nxt]<0) {
            D[nxt] = D[cur] + 1;
            Q.push(nxt);
         }
      }
   }
}

int main() {
    freopen("pathfind.in", "r", stdin);
	 freopen("pathfind.out", "w", stdout);
    int src, x;
    memset(adj,false,sizeof(adj));
    memset(D,-1,sizeof(D));
    scanf("%d%d",&N,&src);
    for(int i = 1; i <= N; ++i) {
       for(int j = 1; j <= N; ++j) {
         scanf("%d",&x);
         if(x) adj[i][j] = true;
       }
    }
    bfs(src);
    vector<vector<int> > ans(N+1);
    for(int d = 0; d < N; ++d) {
       for(int j = 1; j <= N; ++j) {
          if(D[j]==d) ans[d].push_back(j);
       }
    }
    for(int i = 0; i < N; ++i) {
       bool found = false;
       for(int j = 0; j < sz(ans[i]); ++j) {
          if(j > 0) putchar(' ');
          printf("%d",ans[i][j]);
          found = true;
       }
       if(found) putchar('\n');
    }
    return 0;
}
