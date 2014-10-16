/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10487  C++  "Binary Search" */
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

typedef vector<int> VI;
VI sum;
int A[1002];

int main(int argc, char *argv[]) {
   int N, Q, m, lo, tc = 0;
   while(scanf("%d",&N)==1) {
      if(N==0) break;
      sum.clear();
      for(int i = 0; i < N; ++i)
         scanf("%d",&A[i]);
      for(int i = 0; i < N; ++i) {
         for(int j = i + 1; j < N; ++j) {
            sum.push_back(A[i] + A[j]);
         }
      }
      scanf("%d",&Q);
      sort(all(sum));
      printf("Case %d:\n",++tc);
      while(Q-- > 0) {
         scanf("%d",&m);
         if(binary_search(all(sum),m)) {
            printf("Closest sum to %d is %d.\n",m,m);
         } else {
            lo = lower_bound(all(sum),m) - sum.begin();
            if(lo > 0) {
               if(abs(m - sum[lo-1]) < abs(m - sum[lo]))
                  printf("Closest sum to %d is %d.\n",m, sum[lo-1]);   
               else
                  printf("Closest sum to %d is %d.\n",m, sum[lo]);
            } else {
               printf("Closest sum to %d is %d.\n",m, sum[lo]);
            }
         }
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
