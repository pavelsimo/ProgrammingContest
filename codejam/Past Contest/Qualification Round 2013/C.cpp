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

const llong MAXN = 100000000000200LL;
const int SZ = 39;

llong pals[] = {
   1,
   4,
   9,
   121,
   484,
   10201,
   12321,
   14641,
   40804,
   44944,
   1002001,
   1234321,
   4008004,
   100020001,
   102030201,
   104060401,
   121242121,
   123454321,
   125686521,
   400080004,
   404090404,
   10000200001,
   10221412201,
   12102420121,
   12345654321,
   40000800004,
   1000002000001,
   1002003002001,
   1004006004001,
   1020304030201,
   1022325232201,
   1024348434201,
   1210024200121,
   1212225222121,
   1214428244121,
   1232346432321,
   1234567654321,
   4000008000004,
   4004009004004,
};

int solve(llong N) {
   int res = 0;
   for(int i = 0; i < SZ; ++i) {
      if(pals[i] > N) break;
      res++;
   }
   return res;
}

int main(int argc, char *argv[]) { 
   int TC;
   llong A, B;
   scanf("%d",&TC);
   for(int tc = 1; tc <= TC; ++tc) {
      scanf("%lld%lld",&A,&B);
      printf("Case #%d: %d\n",tc, solve(B) - solve(A - 1));
   }
   return 0;
}
