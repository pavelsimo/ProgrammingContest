/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ SEVENTH C++ "Ad Hoc" */
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

typedef long long llong;

int main(int argc, char *argv[]) {
   vector<llong> P, S;
   llong pow7 = 7;
   for(int i = 0; i < 19; ++i) {
      P.push_back(pow7);
      pow7*=7LL;
   }
   int M = 1 << 19;
   for(int i = 1; i < M; ++i) {
      llong sum = 0LL;
      for(int j = 0; j < 19; ++j)
         if(i & (1<<j)) sum+=P[j];
      S.push_back(sum);
   }
   sort(all(S));
   int TC, N;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d",&N);
      printf("%lld\n",S[N-1]);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
