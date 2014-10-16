/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ TWOSQRS C++ "Ad Hoc, Math" */
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


typedef long long llong;

bool issumsq(llong n) {
   llong lo = 0;
   llong hi = sqrt(n);
   while(lo <= n && lo <= hi) {
      llong x = n - (lo*lo + hi*hi);
      if(x > 0)
         lo++;
      else if(x < 0)
         hi--;
      else
         return true;
   }
   return false;
}

int main(int argc, char *argv[]) {
   int TC;
   llong n;
   scanf("%d",&TC);   
   while(TC-- > 0) {
      scanf("%lld",&n);
      if(issumsq(n)) puts("Yes");
      else puts("No");
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
