/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11876  C++  "Binary Search" */
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

const int MAXN = 1000010, MAXM = 100010;
typedef long long llong;
llong D[MAXN], N[MAXN];

void sieve() {
   fill(D,D+MAXN,1);
   D[0] = 0;
   for(int i = 2; i < MAXN; ++i)
     for(int j = i; j < MAXN; j+=i) 
         D[j]++;
   N[0] = 1;
   for(int i = 1; i < MAXM; ++i)
      N[i] = N[i-1] + D[N[i-1]];
}

int main(int argc, char *argv[]) {
   sieve();
   int TC, lo, hi;
   llong A, B;
   scanf("%d",&TC);
   for(int tc = 1; tc <= TC; ++tc) {
      scanf("%lld%lld",&A,&B);
      lo = lower_bound(N,N+MAXM,A) - N;
      hi = upper_bound(N,N+MAXM,B) - N;
      printf("Case %d: %d\n",tc,hi-lo);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
