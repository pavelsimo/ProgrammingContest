/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ FCTRL C++ "Math, Factorial" */
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

int main(int argc, char *argv[]) {
   int TC, N;
   llong res;
   scanf("%d",&TC);
   while(TC-- > 0) {
      res=0LL;
      scanf("%d",&N);
      for(llong i = 5LL; i <= N; i*=5LL)
         res+=floor(N/i);
      printf("%lld\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
