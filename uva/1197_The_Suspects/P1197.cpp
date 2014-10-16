/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  1197  C++  "Graph Theory, DFS" */
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
const int MAXN = 30002;
int N, M;
VVI adj;
VVI members;
bool seen[MAXN];

int dfs(int student) {
   if(seen[student]) return 0;
   seen[student] = true;
   int res = 1;
   for(int i = 0; i < sz(adj[student]); ++i) {
      int group = adj[student][i];
      for(int j = 0; j < sz(members[group]); ++j) {
         int nxt_student = members[group][j];
         res+=dfs(nxt_student);
      }
   }
   return res;
}

int main(int argc, char *argv[]) {
   int k, student;
   while(2 == scanf("%d%d",&N,&M)) {
      if(!N && !M) break;
      memset(seen,false,sizeof(seen));
      adj = VVI(N + 1);
      members = VVI(M + 1);
      for(int group = 0; group < M; ++group) {
         scanf("%d",&k);
         for(int j = 0; j < k; ++j) {
            scanf("%d",&student); 
            adj[student].push_back(group);
            members[group].push_back(student);
         }
      }
      printf("%d\n",dfs(0));
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
