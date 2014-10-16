/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  1152  C++  "Binary Search" */
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

int L[16080100], A[4010], B[4010], C[4010], D[4010];
int N, M;

int main(int argc, char *argv[]) {
   int TC;
   llong ans;
   scanf("%d",&TC);
   for(int tc = 0; tc < TC; ++tc) {
      if(tc > 0) putchar('\n');
      scanf("%d",&N);
      for(int i = 0; i < N; ++i)
         scanf("%d%d%d%d",&A[i],&B[i],&C[i],&D[i]);
      ans=0LL;
      M=0;
      for(int i = 0; i < N; ++i) {
         for(int j = 0; j < N; ++j) {
            L[M++]=A[i]+B[j];
         }
      }
      sort(L,L+M);
      pair<int*,int*> it;
      for(int i = 0; i < N; ++i) {
         for(int j = 0; j < N; ++j) {
            it=equal_range(L,L+M,-C[i]-D[j]);
            ans+=it.second-it.first;
         }
      }
      printf("%lld\n",ans);  
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
