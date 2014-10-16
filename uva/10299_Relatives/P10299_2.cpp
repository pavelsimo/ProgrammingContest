/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10299  C++  "Math, Inclusion-Exclusion Principle" */
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
#define BITCOUNT(n) __builtin_popcount(n)

int main(int argc, char *argv[]) {
   llong n, x, prod, res;
   bool found;
   while(1 == scanf("%lld",&n)) {
      if(!n) break;
      pf.clear();
      x = n;
      for(llong i = 2LL; i * i <= x; ++i) {
         found = false;
         while(x % i == 0) {
            found = true;
            x/=i;
         }
         if(found) pf.push_back(i);
      }
      if(x > 1) pf.push_back(x);
      res = n;
      for(int i = 1; i < (1<<sz(pf)); ++i) {
         prod = 1;
         for(int j = 0; j < sz(pf); ++j) {
            if(i & (1<<j)) 
               prod*=pf[j];
         }
         if(BITCOUNT(i) & 1)
            res-=(n/prod);
         else
            res+=(n/prod);
      }
      printf("%lld\n", n == 1 ? 0 : res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
