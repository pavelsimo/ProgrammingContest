/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  1213  C++  "Dynamic Programming, Primes" */
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

const int MAXN = 1502;
bool prime[MAXN];
vector<int> P;

int memo[1122][15][188];

void sieve() {
   for(int i = 2; i < MAXN; ++i)
      prime[i] = true;
   prime[0] = false;
   prime[1] = false;
   int N = 1120;
   for(int i = 2; i < N; ++i) {
      if(prime[i]) {
         P.push_back(i);
         for(int j = i + i; j < N; j+=i)
            prime[j] = false;   
      }
   }
}

int rec(int n, int k, int i) {
   if(n == 0 && k == 0) return 1;
   if(k == 0 || i >= sz(P)) return 0;   
   if(memo[n][k][i] >= 0) 
      return memo[n][k][i];
   int res = rec(n, k, i + 1);
   if(n >= P[i]) 
      res += rec(n - P[i], k - 1, i + 1);
   return memo[n][k][i] = res;
}

int main(int argc, char *argv[]) {
   sieve();
   int n, k;
   while(2 == scanf("%d%d",&n,&k)) {
      if(!n && !k) break;
      memset(memo,-1,sizeof(memo));
      printf("%d\n",rec(n,k,0));
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
