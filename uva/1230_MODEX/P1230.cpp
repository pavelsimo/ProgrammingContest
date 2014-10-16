/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  1230  C++  "Math, Big Mod" */
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

llong MOD;

llong rec(int n, int exp) {
   if(exp == 0LL) 
      return 1LL;
   if(exp & 1) {
      return ((n%MOD)*(rec(n,exp - 1)%MOD))%MOD;
   } else {
      llong a = rec(n,exp >> 1) % MOD;   
      return (a*a) % MOD;   
   }
}

int main(int argc, char *argv[]) {
   int TC;
   llong x, y;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%lld%lld%lld",&x,&y,&MOD);
      printf("%lld\n",rec(x,y));
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
