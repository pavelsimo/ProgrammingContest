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
typedef vector<llong> VI;

VI psq;

int main(int argc, char *argv[]) {
   for(llong i = 0; i*i <= 1000000000000LL; ++i)
      psq.push_back(i*i);
   int TC;
   llong n;
   scanf("%d",&TC);   
   while(TC-- > 0) {
      scanf("%lld",&n);
      bool found = false;
      for(llong i = 1; i*i <= n; ++i) {
         llong x = n - i*i;
         if(binary_search(psq.begin(),psq.end(),x)) {
            DEBUG(x);
            found = true;
            break;
         }
      }
      if(found) puts("Yes");
      else puts("No");
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
