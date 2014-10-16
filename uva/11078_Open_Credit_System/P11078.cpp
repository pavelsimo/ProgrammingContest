/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11078  C++  "Ad Hoc, Greedy" */
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

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 100020;
int A[100020], mi[MAXN], ma[MAXN];

int main(int argc, char *argv[]) {
   int TC, n;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d",&n);
      for(int i = 0; i < n; ++i) 
         scanf("%d",&A[i]);
      ma[0] = 0;
      mi[n-1] = n-1;
      for(int i = 1; i < n; ++i) {
         if(A[i] > A[ma[i-1]]) ma[i] = i;  
         else ma[i] = ma[i-1];
      }
      for(int i = n - 2; i >= 0; --i) {
         if(A[i] < A[mi[i+1]]) mi[i] = i;
         else mi[i] = mi[i+1];
      }
      int res = -INF;
      for(int i = 1; i < n; ++i)
         res = max(res, A[ma[i-1]] - A[mi[i]]);
      printf("%d\n", res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
