/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ C++ "Binary Search, lower_bound, upper_bound" */
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

int P[1000010], L[102];

int main(int argc, char *argv[]) {
   int N, M, ans;
   scanf("%d",&N);
   for(int i = 0; i < N; ++i)
      scanf("%d",&L[i]);
   M=ans=0;
   for(int a = 0; a < N; ++a) {
      for(int b = 0; b < N; ++b) {
         for(int c = 0; c < N; ++c) {
            P[M++] = L[a]*L[b]+L[c];
         }
      }
   }
   sort(P,P+M);
   pair<int*,int*> it;
   for(int d = 0; d < N; ++d) {
      if(L[d]==0) continue;
      for(int f = 0; f < N; ++f) {
         for(int e = 0; e < N; ++e) {
            it = equal_range(P,P+M,L[d]*(L[f]+L[e]));
            ans+=it.second-it.first;
         }
      }
   }
   printf("%d\n",ans);
   return 0;
}
/* @END_OF_SOURCE_CODE */

