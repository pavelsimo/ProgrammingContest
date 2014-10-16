/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12068  C++  "Ad Hoc" */
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
const int MAXN = 102;
int a[MAXN];

template<typename INT>
INT gcd(INT a, INT b) {
   if (a < 0) a = -a;
   if (b < 0) b = -b;
   if (a < b) swap(a, b);
   while (b > 0) {
      INT t = b;
      b = a % b;
      a = t;
   }
   return a > 0 ? a : 1;
}

template<typename INT>
INT lcm(INT a, INT b) {
   return a / gcd(a,b) * b;
}

int main(int argc, char *argv[]) {
   int TC, N;
   llong p, q, t;
   scanf("%d",&TC);
   for(int tc = 1; tc <= TC; ++tc) {
      scanf("%d",&N);
      q = 1LL; p = 0LL;
      for(int i = 0; i < N; ++i) {
         scanf("%d",&a[i]);
         q = lcm(q,llong(a[i]));
      }
      for(int i = 0; i < N; ++i)
         p+=q/llong(a[i]);
      q*=llong(N);
      t = gcd(p,q);
      printf("Case %d: %lld/%lld\n",tc,q/t,p/t);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
