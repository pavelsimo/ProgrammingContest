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

const int INF = 100000000;
int A[1002];

int main(int argc, char *argv[]) {
   int N, Q, m, lo, tc = 0, res;
   while(scanf("%d",&N)==1) {
      if(N==0) break;
      for(int i = 0; i < N; ++i)
         scanf("%d",&A[i]);
      sort(A,A+N);
      scanf("%d",&Q);
      printf("Case %d:\n",++tc);
      while(Q-- > 0) {
         scanf("%d",&m);
         res = INF;
         for(int i = 1; i < N; ++i) {
            lo = lower_bound(A,A+i,m-A[i])-A;
            if(lo==i) lo--;
            if(lo > 0) {
               if(abs(A[i]+A[lo-1]-m) < abs(res-m)) 
                  res = A[i]+A[lo-1];
            }
            if(abs(A[i]+A[lo]-m) < abs(res-m)) 
               res = A[i]+A[lo];
         }
         printf("Closest sum to %d is %d.\n",m, res);
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
