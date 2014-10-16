/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11138  C++  "Bipartite Matching" */
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


typedef vector<int> VI;
typedef vector<VI> VVI;
const int MAXN = 1024;
VI L, R;
VVI edges;
vector<bool> seen;
int N, M;

bool dfs(int cur) {
   if(seen[cur]) 
      return false;
   seen[cur] = true;
   for(int i = 0; i < sz(edges[cur]); ++i) {
      int nxt = edges[cur][i];
      if(R[nxt] == -1 || dfs(R[nxt])) {
         L[cur] = nxt;
         R[nxt] = cur;
         return true;  
      }
   }
   return false;
}

int match() {
   int res = 0;
   bool aug_path;
   while(true) {  
      aug_path = false;
      seen = vector<bool>(N + 1);
      for(int i = 0; i < N; ++i) {
         if(L[i]==-1 && dfs(i))
            aug_path = true;
      }
      if(!aug_path) break;
   }
   for(int i = 0; i < N; ++i) 
      res+=(L[i]!=-1);
   return res;
}

int main(int argc, char *argv[]) {
   int TC, u;
   scanf("%d",&TC);
   for(int tc = 1; tc <= TC; ++tc) {
      scanf("%d%d",&N,&M);
      L = VI(N + 1, -1);
      R = VI(M + 1, -1);
      edges = VVI(N + 1);
      for(int i = 0; i < N; ++i) {
         for(int j = 0; j < M; ++j) {
            scanf("%d",&u);
            if(u) edges[i].push_back(j);
         }
      }
      printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n",tc,match());
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
