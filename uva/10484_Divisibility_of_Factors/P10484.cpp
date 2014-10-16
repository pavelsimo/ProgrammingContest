/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10484  C++  "Math, Prime Factor" */
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

const int MAXP = 46340;
vector<bool> P;
vector<llong> primes;

void sieve() {
   P = vector<bool>(MAXP + 2, true);
   P[0] = P[1] = false;
   for(llong i = 2; i <= MAXP; ++i) {
      if(P[i]) {
         primes.push_back(i);
         for(llong j = i * i; j <= MAXP; j+=i) 
            P[j] = false;
      }
   }
}

int main(int argc, char *argv[]) {
   sieve();
   int n, d;
   llong res;
   while(2 == scanf("%d%d",&n,&d)) {
      if(!n && !d) break;
      map<int,int> freq;
      res = 1LL;
      for(int k = n; k >= 2; --k) {
         llong n1 = k;
         for(int i = 0; primes[i]*primes[i] <= n1 && i < sz(primes); ++i) {
            while(n1 % primes[i] == 0) {
               freq[primes[i]]++;
               n1/=primes[i];
            }         
         }
         if(n1 > 1) freq[n1]++;         
      }
      llong d1 = d;
      for(int i = 0; primes[i]*primes[i] <= d1 && i < sz(primes); ++i) {
         while(d1 % primes[i] == 0) {
            freq[primes[i]]--;
            d1/=primes[i];
         }         
      }
      if(d1 > 1) freq[d1]--;
      foreach(it,freq) {
         if(it->second < 0) {
            res = 0LL;
            break;
         }
         res*=(it->second + 1LL);
      }
      printf("%lld\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
