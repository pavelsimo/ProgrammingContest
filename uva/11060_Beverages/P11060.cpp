/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11060  C++  "Graph Theory, DFS, Topological Sort" */
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

int N, M;
const int MAXN = 102;
char buf[64], s1[64], s2[64];
map<string,int> m_id;
int in_deggre[MAXN];
bool seen[MAXN];
priority_queue<int, vector<int>, greater<int> > Q;
VVI adj;
vector<string> A;

void bfs() {
   while(!Q.empty()) {
      int cur = Q.top();
      printf(" %s",A[cur].c_str());
      Q.pop();
      for(int i = 0; i < sz(adj[cur]); ++i) {
         int nxt = adj[cur][i];
         if(--in_deggre[nxt]==0) {
            Q.push(nxt);
         }
      }
   }   
}

int main(int argc, char *argv[]) {
   int u, v;
   for(int tc = 1; scanf("%d",&N)==1; ++tc) {
      adj = VVI(N+1);
      memset(in_deggre,0,sizeof(in_deggre));
      memset(seen,false,sizeof(seen));
      m_id.clear();
      A.clear();
      for(int i = 0; i < N; ++i) {
         scanf("%s",buf);
         m_id[buf] = i;
         A.push_back(buf);
      }
      scanf("%d",&M);
      for(int i = 0; i < M; ++i) {
         scanf("%s%s",s1,s2);
         u = m_id[s1];
         v = m_id[s2];
         in_deggre[v]++;
         adj[u].push_back(v);
      }
      for(int i = 0; i < N; ++i) 
         if(in_deggre[i]==0)
            Q.push(i);
      printf("Case #%d: Dilbert should drink beverages in this order:",tc);
      bfs();
      puts(".");
      putchar('\n');
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
