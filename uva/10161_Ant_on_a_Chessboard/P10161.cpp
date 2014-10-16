/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID: 4217 10161 C++  "Ad Hoc, Math" */
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

llong f(llong n) {
   return llong(ceil(sqrt(n)));
}

llong g(llong n) {
   return 2LL * n - 1LL;
}

llong c(llong n) {
   return llong(ceil(n*n-g(n)/2.0));
}

int main(int argc, char *argv[]) {
   llong n, i, j, mid;
   while(scanf("%lld",&n) == 1) {
      if(!n) break;
      i = j = f(n);
      mid = c(i);
      if(i % 2 == 0) {
        if(n <= mid) i = i - (mid-n);
        else j = j - (n-mid); 
      } else {
         if(n <= mid) j = j - (mid-n);
         else i = i - (n-mid);
      }
      printf("%lld %lld\n",i,j);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
