/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  1189  C++  "Ad Hoc, Math" */
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

bool seen[202];

struct State {
   int n;
   int mod;
   State(int _n, int _mod) : 
      n(_n), mod(_mod) {}
};

int highestbit(int n) {
   for(int i = 31; i >= 0; --i)
      if(n&(1<<i)) return i;
   return 0;
}

int main(int argc, char *argv[]) {
   int N;
   while(1 == scanf("%d",&N)) {
      if(!N) break;
      memset(seen,false,sizeof(seen));
      queue<State> Q;
      Q.push(State(1,1%N));
      while(!Q.empty()) {
         State cur = Q.front(); Q.pop();
         if(cur.mod==0) {
            for(int i = highestbit(cur.n); i >= 0; --i)
               printf("%d",(cur.n & (1<<i))?1:0);
            putchar('\n');
            break;
         }
         if(seen[cur.mod]) continue;
         seen[cur.mod] = true;
         Q.push(State(cur.n<<1,(cur.mod*10)%N));
         Q.push(State((cur.n<<1)|1,(cur.mod*10+1)%N));
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
