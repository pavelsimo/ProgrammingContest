/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ FASHION C++ "Ad Hoc" */
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

const int MAXN = 1010;
int W[MAXN], M[MAXN];

int main(int argc, char *argv[]) {
   int TC, N, ans;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d",&N);
      for(int i = 0; i < N; ++i)
         scanf("%d",M+i);
      for(int i = 0; i < N; ++i)
         scanf("%d",W+i);
      sort(M,M+N);
      sort(W,W+N);
      ans=0;
      for(int i = 0; i < N; ++i)
         ans+=M[i]*W[i];
      printf("%d\n",ans);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

