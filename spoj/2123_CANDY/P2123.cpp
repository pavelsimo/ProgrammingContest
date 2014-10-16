/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ CANDY C++ "Ad Hoc" */
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
typedef long long llong;

const int MAXN = 10010;
int A[MAXN];

int main(int argc, char *argv[]) {
   int N, k, ans, threshold;
   while(1==scanf("%d",&N)) {
      if(N==-1) break;
      k=ans=threshold=0;
      for(int i = 0; i < N; ++i) {
         scanf("%d",A+i);
         k+=A[i];
      }
      k/=N;
      for(int i = 0; i < N; ++i) {
         if(A[i] > k) {
            threshold+=A[i]-k;
            ans+=A[i]-k;
         } else if(A[i] < k) {
            threshold+=A[i]-k;
         }
      }
      if(threshold==0) printf("%d\n",ans);
      else puts("-1");
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

