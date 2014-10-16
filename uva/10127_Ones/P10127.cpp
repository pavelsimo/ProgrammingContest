/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10127  C++  "Number Theory, Mode" */
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
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

typedef long long llong;

int main(int argc, char *argv[]) {
   llong MOD;
   int res;
   while(1==scanf("%lld",&MOD)) {
      llong pow10 = 0;
      res = 1;
      if(MOD > 0) {
         for(res = 1; true; ++res) {
            pow10 = (pow10*10 + 1) % MOD;
            if(!pow10) break;
         }         
      }
      printf("%d\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
