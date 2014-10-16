/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10176  C++  "Number Theory, Mode" */
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

const llong MOD = 131071LL;
const int MAXN = 1024;
char buf[MAXN];

int main(int argc, char *argv[]) {
   int N;
   llong res, pow2;
   pow2 = 1LL;
   res = 0LL;
   while(gets(buf)) {
      N = strlen(buf);
      for(int i = 0; i < N; ++i) {
         if(buf[i]=='#') {            
            if(!res) puts("YES");
            else puts("NO");            
            pow2 = 1LL;
            res = 0LL;
            break;
         }
         if(buf[i]-'0') 
            res = (res + pow2) % MOD;
         pow2 = (pow2 << 1LL) % MOD;
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
