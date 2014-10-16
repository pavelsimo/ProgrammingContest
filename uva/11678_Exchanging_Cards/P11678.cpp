/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11678  C++  "Ad Hoc, Frequency" */
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

const int MAXN = 100002;
bool A[MAXN], B[MAXN];

int main(int argc, char *argv[]) {
   int N, M, u, lo, hi, sa, sb;
   memset(A,false,sizeof(A));
   memset(B,false,sizeof(B));
   while(2 == scanf("%d%d",&N,&M)) {
      if(!N && !M) break;
      sa = sb = hi = 0;
      lo = MAXN - 1;
      for(int i = 0; i < N; ++i) {
         scanf("%d",&u);
         lo = min(lo,u);
         hi = max(hi,u);
         A[u] = true;
      }
      for(int i = 0; i < M; ++i) {
         scanf("%d",&u);
         lo = min(lo,u);
         hi = max(hi,u);
         B[u] = true;
      }
      for(int i = lo; i <= hi; ++i) {
         if(A[i] && !B[i]) sa++;
         else if(!A[i] && B[i]) sb++;
         A[i] = B[i] = false;
      }
      printf("%d\n",min(sa,sb));
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
