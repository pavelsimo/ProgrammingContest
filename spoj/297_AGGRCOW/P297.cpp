/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ AGGRCOW C++ "Binary Search" */
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

int N, C;
const int MAXN = 100002;
llong a[MAXN];

bool check(llong distance) {
   int cnt = C-1;
   int sum = 0;
   for(int i = 1; i < N && cnt > 0; ++i) {
      sum+=a[i]-a[i-1];
      if(sum > distance) {
         cnt--;
         sum=0;
      }  
   }
   return cnt==0;
}

int main(int argc, char *argv[]) {
   int TC;
   llong mid, lo, hi;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d%d",&N,&C);
      for(int i = 0; i < N; ++i)
         scanf("%lld",a+i);
      sort(a,a+N);
      lo = 0LL;
      hi = 1000000000LL;
      while(lo < hi) {
         mid = lo + (hi-lo)/2LL;
         if(!check(mid))
            hi = mid;
         else 
            lo = mid+1;
      }
      printf("%lld\n",lo);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

