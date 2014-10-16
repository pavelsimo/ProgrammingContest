/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ CHAIR C++ "Ad Hoc" */
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

#define MOD 1000000003LL
typedef long long llong;

llong doit(int n, int k) {
   if(n <= 0) return 0;
   if(k == 0) return 1;
   return doit(n-1, k) + doit(n-2,k-1);
}

int main(int argc, char *argv[]) {
   int n, k;
   while(scanf("%d%d",&n,&k)==2) {
      printf("%lld\n",doit(n,k));
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

