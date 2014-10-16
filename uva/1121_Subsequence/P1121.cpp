/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  1121  C++  "Ad Hoc" */
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

typedef long long llong;

const int INF = 100020;
llong A[100020];

int main(int argc, char *argv[]) {
   llong sum;
   int N, S, lo, hi, res;
   while(2 == scanf("%d%d",&N, &S)) {
      for(int i = 0; i < N; ++i)
         scanf("%lld",&A[i]);
      sum = lo = hi = 0;
      res = INF;
      while(hi < N) {
         sum += A[hi++];
         while(sum >= S && lo < hi) {
            res = min(res, hi - lo);
            sum -= A[lo++];
         }
      }
      printf("%d\n", res >= INF ? 0: res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
