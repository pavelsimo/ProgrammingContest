/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10299  C++  "Math, Euler's Totient (Phi) Function" */
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
vector<llong> pf;

// Euler's Totient (Phi) Function
llong euler_phi(llong n) {
   pf.clear();
   bool factor;
   llong x = n;
   for(llong p = 2; p * p <= x; ++p) {
      factor = false;
      while(x % p == 0) {
         factor = true;
         x/=p;
      }
      if(factor) pf.push_back(p);
   }
   if(x > 1) pf.push_back(x);
   llong res = n;
   for(int i = 0; i < sz(pf); ++i)
      res = res - res/pf[i];
   return res;
}

int main(int argc, char *argv[]) {
   llong n;
   while(1 == scanf("%lld",&n)) {
      if(!n) break;
      printf("%lld\n", n==1 ? 0 : euler_phi(n));
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
