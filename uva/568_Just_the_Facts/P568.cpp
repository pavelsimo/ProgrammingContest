/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  568  C++  "Math, Prime Factor, Factorial" */
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

const int MAXP = 10000;
vector<bool> P;
vector<int> primes;

void sieve() {
   P = vector<bool>(MAXP + 2, true);
   P[0] = P[1] = false;
   for(int i = 2; i <= MAXP; ++i) {
      if(P[i]) {
         primes.push_back(i);
         for(int j = i * i; j <= MAXP; j+=i) 
            P[j] = false;
      }
   }
}

int fact_power(int n, int p) {
   int res = 0;
   for(int i = p; i <= n; i*=p) 
      res+=n/i;
   return res;
}

int power(int base, int exp) {
   if(exp == 0) return 1;
   if(exp & 1) {
      return ((base%10) * (power(base, exp - 1)%10)) % 10;
   } else {
      int t = power(base,exp/2) % 10;
      return (t * t) % 10;
   }
}

int freq[10020];
int main(int argc, char *argv[]) {
   sieve();
   int n, res, t, m;
   while(1 == scanf("%d",&n)) {
      for(m = 0; primes[m] <= n && m < sz(primes); ++m)
         freq[primes[m]] = fact_power(n,primes[m]);
      t = min(freq[2],freq[5]);
      if(freq[2] && freq[5]) 
         freq[2]-=t, freq[5]-=t;
      res = 1;
      for(int i = 0; i < m; ++i) {
         if(freq[primes[i]] > 0)
            res = (res * power(primes[i],freq[primes[i]])) % 10;
      }
      printf("%5d -> %d\n",n,res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
