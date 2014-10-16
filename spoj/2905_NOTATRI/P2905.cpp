/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ C++ "Binary Search, lower_bound, upper_bound" */
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
int a[2010];

int main(int argc, char *argv[]) {
   int N;
   llong ans;
   while(1==scanf("%d",&N)) {
      if(N == 0) break;
      for(int i = 0; i < N; ++i) 
         scanf("%d",&a[i]);
      sort(a,a+N);
      ans=0LL;
      for(int i = 0; i < N-2; ++i) {
         for(int j = i+1; j < N-1; ++j) {
            int c = a[i]+a[j];
            int lower = int(lower_bound(a,a+N,c+1) - a);
            ans+=N-lower;
         }
      }
      printf("%lld\n",ans);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

