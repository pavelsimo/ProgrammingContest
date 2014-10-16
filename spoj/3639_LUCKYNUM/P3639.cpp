/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ LUCKYNUM C++ "BFS, Number Theory" */
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

typedef long long llong;
typedef pair<string,int> State;
const int MAXN = 10010;
bool seen[MAXN][2];

int main(int argc, char *argv[]) {  
   string res;
   int n, TC;
   scanf("%d",&TC);
   while(TC-- > 0) {
      memset(seen, false, sizeof(seen));
      scanf("%d",&n);
      queue<State> Q;
      Q.push(State("6",6%n));
      Q.push(State("8",8%n));
      res = "";
      while(!Q.empty()) {
         State cur = Q.front(); Q.pop();
         int ind = cur.first[sz(cur.first)-1] == '8';
         if(sz(cur.first) > 200 || seen[cur.second][ind]) continue;
         seen[cur.second][ind] = true;
         if(cur.second == 0) {
            res = cur.first;
            break;
         }
         Q.push(State(cur.first+"6",(cur.second*10+6)%n));
         if(ind) Q.push(State(cur.first+"8",(cur.second*10+8)%n));
      }
      if(sz(res)) 
         puts(res.c_str());
      else
         puts("-1");
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
