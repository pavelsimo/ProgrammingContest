/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ ONEZERO C++ "BFS, Graph Theory" */
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
#define BITCOUNT(x) __builtin_popcount(x)

typedef long long llong;

int highestbit(llong n) {
   for(int i = 63; i >= 0; --i)
      if(n&(1LL<<i)) return i;
   return 0;
}

void tobin(llong n) {
   for(int i = highestbit(n); i >= 0; --i)
      printf("%d",(n & (1LL<<i))?1:0);
}

int mod(llong n, int x) {
   int size = highestbit(n);
   llong rem = 0;
   for(int i = size; i >= 0; --i) {
      int d = (n&(1LL<<i))?1:0;
      rem=rem*10+d;
      if(rem >= x)
         rem%=x;
   }  
   return rem;
}

int bfs(int n) {
   queue<llong> Q;
   set<llong> seen;
   Q.push(1LL);
   while(!Q.empty()) { 
      int cur = Q.front(); Q.pop();
      if(seen.count(cur)!=0) continue;
      seen.insert(cur);
      if(mod(cur,n)==0)
         return cur;
      Q.push(cur + 1);
   }
   return -1;
}

int main(int argc, char *argv[]) {
   int TC, n;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d",&n);
      tobin(bfs(n));
      putchar('\n');
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
