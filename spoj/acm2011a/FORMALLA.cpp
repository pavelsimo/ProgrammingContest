/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ FORMALLA C++ "Ad Hoc" */
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

llong f(int n) {
   if(n == 1) return 0;
   int res = 2;
   for(int i = 2; i*2 <= n; ++i) {
      if(n % i == 0) {
         res+=(1LL<<i);
         res-=f(n/i);
      }
   }
   return res;
}

int main(int argc, char *argv[]) {
   int N;
   while(scanf("%d",&N)==1) {
      if(N==0) break;
      printf("%lld\n",f(N));
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
