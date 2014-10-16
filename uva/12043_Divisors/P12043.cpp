/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12043  C++  "Math, Sieve" */
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
const int MAXN = 100002;
int D[MAXN], S[MAXN];

void sieve() {
   for(int i = 0; i < MAXN; ++i)
      D[i] = S[i] = 1;
   S[0] = D[0] = 0;
   for(int i = 2; i < MAXN; ++i) {
      for(int j = i; j < MAXN; j+=i) {
         D[j]++;
         S[j]+=i;
      }
   }
}

int main(int argc, char *argv[]) {
   sieve();
   int TC, a, b, k;
   llong g, h;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d%d%d",&a,&b,&k);
      g = h = 0LL;
      for(int i = a; i <= b; ++i) {
         if(i % k == 0) {
            h+=D[i];
            g+=S[i];
         }
      }
      printf("%lld %lld\n",h,g);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
