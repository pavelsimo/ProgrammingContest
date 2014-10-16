/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ INCSEQ C++ "Binary Search" */
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

const int MAXN = 10002;
const int MOD = 5000000;
int N, K, A[MAXN];
pair<int*,int*> it;


int main(int argc, char *argv[]) {
   scanf("%d%d",&N,&K);
   int lo, hi, cnt, res;
   for(int i = 0; i < N; ++i)
      scanf("%d",A+i);
   res=0;
   for(int i = 0; i < N; ++i) {
      cnt=1;
      lo=hi=i;
      int j;
      for(j = 0; j < K; ++j) {
         int cur = A[hi];
         if(hi >= N) break;
         it = equal_range(A,A+N,cur);
         lo = it.first-A;
         hi = it.second-A;
         //lo = int(lower_bound(A,A+N,cur) - A);
         //hi = int(upper_bound(A,A+N,cur) - A);
         if(j==0) i = hi;
         cnt = ((cnt%MOD)*(hi-lo))%MOD;
      }
      if(j==K)res=(res+cnt)%MOD;
   }
   printf("%d\n",res);
   return 0;
}
/* @END_OF_SOURCE_CODE */
