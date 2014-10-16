/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11292  C++  "Binary Search" */
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

const int MAXN = 20002;
int D[MAXN], C[MAXN];

int main(int argc, char *argv[]) {
   int N, M, res, j;
   while(2 == scanf("%d%d",&N,&M)) {
      if(!N && !M) break;  
      for(int i = 0; i < N; ++i)
         scanf("%d",&D[i]);
      for(int i = 0; i < M; ++i)
         scanf("%d",&C[i]);
      sort(D,D+N);
      sort(C,C+M);
      if(N > M) {
         puts("Loowater is doomed!");
      } else {
         res = j = 0;
         bool dommed = false;
         for(int i = 0; i < N; ++i) {
            j = lower_bound(C + j, C + M, D[i]) - C;
            if(j >= M) {
               dommed = true;
               break;
            }
            res+=C[j];
            ++j;
         }
         if(dommed) puts("Loowater is doomed!");
         else printf("%d\n",res);
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
