/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11045  C++  "Bipartite Matching, BMP" */
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
const int INF = 0x3f3f3f3f;
const int MAXT = 6, MAXN = 40;
const string T[] = {"XXL", "XL", "L", "M", "S", "XS"};
int N, M;
VI L, R;
VVI edges;
bool seen[MAXN];

bool dfs(int cur) {
   if(seen[cur]) return false;
   seen[cur] = true;
   for(int i = 0; i < sz(edges[cur]); ++i) {
      int nxt = edges[cur][i];  
      if(R[nxt]==-1 || dfs(R[nxt])) {
         R[nxt] = cur;
         L[cur] = nxt;
         return true;
      }
   }
   return false;
}

bool check() {
   bool aug_path = false;
   while(true) {
      aug_path = false;
      memset(seen,false,sizeof(seen));
      for(int i = 0; i < M; ++i) {
         if(L[i]==-1 && dfs(i))
            aug_path = true;
      }
      if(!aug_path) break;
   }
   for(int i = 0; i < M; ++i)
      if(L[i]==-1) 
         return false;
   return true;
}

int main(int argc, char *argv[]) {
   int TC, t1, t2;
   string s1, s2;
   cin >> TC;
   while(TC-- > 0) {
      cin >> N >> M;
      int k = N/MAXT;
      edges = VVI(M + 1);
      L = VI(M + 1, -1);
      R = VI(N + 1, -1);
      for(int i = 0; i < M; ++i) {
         cin >> s1 >> s2;
         t1 = int(find(T,T+MAXT,s1) - T);
         t2 = int(find(T,T+MAXT,s2) - T);
         for(int j = 0; j < k; ++j) {
            edges[i].push_back(t1*k + j);
            edges[i].push_back(t2*k + j);
         }
      }
      if(check()) puts("YES");
      else puts("NO");
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
