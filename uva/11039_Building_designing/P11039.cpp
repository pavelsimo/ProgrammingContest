/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11039  C++  "Ad Hoc, Greedy" */
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

const int MAXN = 500002;
const int INF = 0x3f3f3f3f;
int B[MAXN], R[MAXN];

bool cmp(const int a, const int b) {
   return a > b;
}

int main(int argc, char *argv[]) {
   int TC, n, nred, nblue, c, prev, cur;
   int f, res, ri, bi, turn;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d",&n);
      nred = nblue = 0;
      for(int i = 0; i < n; ++i) {
         scanf("%d",&c);
         if(c < 0) R[nred++] = -c;
         else B[nblue++] = c;
      }
      sort(B, B + nblue, cmp);
      sort(R, R + nred,  cmp);
      res = 0;
      for(int k = 0; k <= 1; ++k) {
         turn = k;
         f = ri = bi = 0;
         prev = INF;
         // O(nred + nblue) ~ two pointers
         while(ri < nred || bi < nblue) {
            bool ok = false;
            if(turn) {
               while(ri < nred) {
                  cur = R[ri++];
                  if(cur < prev) {
                     f++;
                     ok = true;
                     break;
                  }
               }
            } else {
               while(bi < nblue) {
                  cur = B[bi++];
                  if(cur < prev) {
                     f++;
                     ok = true;
                     break;
                  }
               }
            }
            if(!ok) break;
            prev = cur;
            turn^=1;
         }
         res = max(res, f);  
      } 
      printf("%d\n",res);
   }
	return 0;
}
/* @END_OF_SOURCE_CODE */
