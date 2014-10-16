/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ COINS C++ "Dynamic Programming" */
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

map<llong,llong> memo;

llong doit(llong n) {
   if(n==0) return 0;
   if(memo.count(n)!=0) return memo[n];
   return memo[n] = max(n,doit(n/2)+doit(n/3)+doit(n/4));
}

int main(int argc, char *argv[]) {
   llong N;
   while(1==scanf("%lld",&N)) {
      printf("%lld\n",doit(N));   
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

