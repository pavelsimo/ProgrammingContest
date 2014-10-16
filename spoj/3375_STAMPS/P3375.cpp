/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ STAMPS C++ "Ad Hoc" */
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

const int MAXN = 1002;
int A[MAXN];

int main(int argc, char *argv[]) {
   int TC, need, N, res;
   scanf("%d",&TC);
   for(int tc = 1; tc <= TC; ++tc) {
      scanf("%d%d",&need,&N);
      for(int i = 0; i < N; ++i)
         scanf("%d",A+i);
      sort(A,A+N);
      res = 0;
      int sum = 0;
      for(int i = N-1; i >= 0 && sum < need; --i) {
         sum+=A[i];
         res++;
      }
      printf("Scenario #%d:\n",tc);
      if(sum < need) puts("impossible");
      else printf("%d\n",res);
      putchar('\n');
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
