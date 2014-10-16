/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ ADOMINO C++ "Binary Search" */
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

int N, D;
const int MAXN = 100002;
llong A[MAXN];

bool check(llong dist) {
   int used = D-1;
   llong sum = 0LL;
   for(int i = 1; i < N && used > 0; ++i) {
      sum+=A[i]-A[i-1];
      if(sum > dist) {
         used--;
         sum = 0LL;
      }
   }
   return used==0;
}

int main(int argc, char *argv[]) {
   int TC;
   llong lo, hi;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d%d",&N,&D);
      for(int i = 0; i < N; ++i)
         scanf("%lld",A+i);
      sort(A,A+N);
      lo = 0LL;
      hi = 1000000000LL;
      while(lo < hi) {
         llong mid = lo + (hi-lo)/2;
         if(check(mid))
            lo = mid + 1;
         else
            hi = mid;
      }
      printf("%lld\n",lo);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
