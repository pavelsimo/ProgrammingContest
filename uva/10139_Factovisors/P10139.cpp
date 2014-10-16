/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10139  C++  "Math, Factorial" */
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

typedef vector<bool> VS;
typedef vector<llong> VL;
const int MAXP = 46340, M = 216;

VS P;
VL primes;

void sieve() {
   P = VS(MAXP + 2, true);
   P[0] = false;
   P[1] = false;
   for(llong i = 2; i <= MAXP; ++i) {
      if(P[i]) {
         primes.push_back(i);
         for(llong j = i * i; j <= MAXP; j+=i)
            P[j] = false;
      }
   }
}

llong getpower(llong n, llong p) {
   llong res = 0;
   for(llong power = p; power <= n; power*=p)
      res+=n/power;
   return res;
}

bool check(llong n, llong k) {
   llong x = k;
   for(int i = 0; primes[i]*primes[i] <= x && i < sz(primes); ++i) {
      if(x % primes[i] == 0) {
         llong cnt1 = 0, cnt2 = 0;
         while(x % primes[i] == 0) {
            cnt1++;
            x/=primes[i];
         }
         cnt2 = getpower(n, primes[i]);
         if(cnt1 > cnt2) return false;
      }  
   }
   if(x > 1 && getpower(n,x) < 1) 
      return false;
   return true;
}

int main(int argc, char *argv[]) {
   sieve();
   llong n, k;
   while(2 == scanf("%lld%lld",&n,&k)) {
      if(n == 0 && k == 1) printf("%lld divides %lld!\n",k,n);
      else if(n == 0 || k == 0) printf("%lld does not divide %lld!\n",k,n);
      else if(check(n,k)) printf("%lld divides %lld!\n",k,n);
      else printf("%lld does not divide %lld!\n",k,n);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
