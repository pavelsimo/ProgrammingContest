/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12101  C++  "BFS, Primes" */
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

const int MAXN = 10002;
bool seen[MAXN], prime[MAXN];
char buf[16];

struct State { 
   int n, dist;
   State(int _n, int _dist) : 
      n(_n), dist(_dist) {}
};

void sieve() {
   for(int i = 2; i < MAXN; ++i)
      prime[i] = true;
   prime[0] = false;
   prime[1] = false;
   for(int i = 2; i < MAXN; ++i) {
      if(prime[i]) {
         for(int j = i + i; j < MAXN; j+=i)
            prime[j] = false;   
      }
   }
}

int main(int argc, char *argv[]) {
   sieve();
   int TC, src, dst, nxt;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d%d",&src,&dst);
      memset(seen,false,sizeof(seen));
      queue<State> Q;
      Q.push(State(src,0));
      while(!Q.empty()) {
         State cur = Q.front(); Q.pop();
         if(cur.n == dst) {
            printf("%d\n",cur.dist);
            break;
         }
         sprintf(buf,"%d",cur.n);
         for(int i = 0; i < 4; ++i) {
            for(char ch = !i ? '1': '0'; ch <= '9'; ++ch) {
               char t = buf[i];
               buf[i] = ch;
               sscanf(buf,"%d",&nxt);
               if(!seen[nxt] && prime[nxt]) {
                  Q.push(State(nxt, cur.dist + 1));
                  seen[nxt] = true;
               }
               buf[i] = t;
            }
         }
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
