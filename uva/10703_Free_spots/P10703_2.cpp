/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10703  C++  "Ad Hoc" */
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
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

typedef long long llong;

const int MAXN = 502;
int A[MAXN][MAXN];

int main(int argc, char *argv[]) {
   int W, H, N, X1, Y1, X2, Y2;
   while(3 == scanf("%d%d%d",&W,&H,&N)) {
      if(!W && !H && !N) break;
      memset(A, 0, sizeof(A));
      int res = W * H;
      for(int i = 0; i < N; ++i) {
         scanf("%d%d%d%d",&X1, &Y1,&X2, &Y2);
         X1--, Y1--, X2--, Y2--;
         if(X1 > X2) swap(X1,X2);
         if(Y1 > Y2) swap(Y1,Y2);
         for(int j = X1; j <= X2; ++j) {
            for(int k = Y1; k <= Y2; ++k) {
               if(!A[j][k]) {
                  res--;
                  A[j][k] = 1;
               }
            }
         }
      }
      if(res == 0) printf("There is no empty spots.\n");
      else if(res == 1) printf("There is one empty spot.\n");
      else printf("There are %d empty spots.\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

