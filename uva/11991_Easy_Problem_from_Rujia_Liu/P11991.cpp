/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11991  C++  "Ad Hoc, Data Structure" */
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
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

typedef vector<int> VI;
typedef vector<VI> VVI;

const int MAXN = 1000010;
int N, M;
VVI adj;

int main(int argc, char *argv[]) {
   int k, v, x;
   while(2==scanf("%d%d",&N,&M)) {
      adj = VVI(MAXN);
      for(int i = 1; i <= N; ++i) {
         scanf("%d",&x);
         adj[x].push_back(i);
      }
      for(int i = 0; i < M; ++i) {
         scanf("%d%d",&k,&v);
         if(sz(adj[v]) < k) puts("0");
         else printf("%d\n",adj[v][k-1]);
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

