/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11934  C++  "Ad Hoc, Simple Math" */
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

llong a, b, c, d, L;

llong f(llong x) {
   return a*x*x + b*x + c;
}

int main(int argc, char *argv[]) {
   int res;
   while(scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&d,&L)==5) {
      if(a==0 && b==0 && c==0 && d==0 && L==0) break;
      res = 0;
      for(int x = 0; x <= L; ++x) {
         if(f(x)%d==0LL) 
            res++;
      }
      printf("%d\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
