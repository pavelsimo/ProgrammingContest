/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12527  C++  "Ad Hoc" */
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

bool check(int n) {
   int freq[10];
   memset(freq, 0, sizeof(freq));
   while(n > 0) {
      int d = n % 10;
      freq[d]++;
      if(freq[d] >= 2) return false;
      n/=10;
   }
   return true;
}


int main(int argc, char *argv[]) {
   int N, M, res;
   while(2 == scanf("%d%d",&N,&M)) {
      res = 0;
      if(M < N) swap(N, M);
      for(int x = N; x <= M; ++x)
         if(check(x)) res++;
      printf("%d\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

