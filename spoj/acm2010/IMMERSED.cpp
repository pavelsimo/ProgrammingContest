/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ IMMERSED C++ "Binary Search" */
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

llong P;
int C;

int main(int argc, char *argv[]) {
   int TC;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%lld%d",&P,&C);
      double lo = 1;
      double hi = 100000000;
      for(int i = 0; i < 100; ++i) {
         double mid = lo + (hi-lo)/2.0;
         if(log10(P/mid) > C*mid*log10(mid)) 
            lo = mid;
         else 
            hi = mid;
      }
      printf("%.6lf\n",lo);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
