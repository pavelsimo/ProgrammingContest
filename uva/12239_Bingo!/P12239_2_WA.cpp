/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12239  C++  "Ad Hoc" */
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

int N, M;
const int MAXN = 102;
int A[MAXN];

int bsearch(int x) {
   int lo = 0;
   int hi = M-1;
   while(lo < hi) {
      int mid = (lo + hi) / 2;
      if(A[mid] < x)
         lo = mid + 1;
      else
         hi = mid;
   }
   return A[lo] == x ? lo : -1;
}

int main(int argc, char *argv[]) {
   while(2 == scanf("%d%d",&N,&M)) {
      if(!N && !M) break;
      for(int i = 0; i < M; ++i)
         scanf("%d",&A[i]);
      sort(A,A+M);
      bool ok = true;
      for(int n = 1; n <= N; ++n) {
         bool found = false;
         for(int j = 0; j < M; ++j) {
            int t = bsearch(abs(n - A[j]));
            if(t >= 0 && t != j) {
               found = true;
               break;
            }
         }
         if(!found) {
            ok = false;
            break;
         }
      }
      if(ok) puts("Y");
      else puts("N");
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
