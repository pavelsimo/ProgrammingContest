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

bool seen[20002];

int highestbit(int n) {
   for(int i = 31; i >= 0; --i)
      if(n&(1<<i)) return i;
   return 0;
}

void tobin(int n) {
   for(int i = highestbit(n); i >= 0; --i)
      printf("%d",(n & (1<<i))?1:0);
   putchar('\n');
}

struct Node {
   int n;
   int mod;
   Node(int _n, int _mod) : 
      n(_n), mod(_mod) {}
};

int bfs(int n) {
   memset(seen,false,sizeof(seen));
   queue<Node> Q;
   Q.push(Node(1,1%n));
   while(!Q.empty()) {
      Node cur = Q.front(); Q.pop();
      if(cur.mod==0) 
         return cur.n;
      if(seen[cur.mod]) continue;
      seen[cur.mod] = true;
      Q.push(Node(cur.n<<1,(cur.mod*10)%n));
      Q.push(Node((cur.n<<1)|1,(cur.mod*10+1)%n));
   }   
   return 0;
}

int main(int argc, char *argv[]) {
   int TC, n;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d",&n);
      tobin(bfs(n));
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
