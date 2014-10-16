/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  530  C++  "Math, Combinations" */
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

llong nCr(int n, int r) {
   llong res = 1LL;
   if(r > n/2) r = n - r;
   for(llong i = 1; i <= r; ++i) {
      res*=n;
      res/=i;
      n--;
   }
   return res;   
}

int main(int argc, char *argv[]) {
   int n, r;
   while(2 == scanf("%d%d",&n,&r)) {
      if(!n && !r) break;
      printf("%lld\n",nCr(n,r));
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
