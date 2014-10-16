/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  696  C++  "Ad Hoc, Chess" */
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

int main(int argc, char *argv[]) {
   int N, M, res;
   while(scanf("%d%d",&N,&M)==2) {
      if(N==0 && M==0) break;
      if(N==1 || M==1) {
         res = max(N,M);
      } else if(N==2 || M==2) {
         res = ((N*M>>3)<<2) + min(4,(N*M)&7);
      } else {
         if(N&1)
            if(M&1) res=((N+1)>>1)*((M+1)>>1)+(N>>1)*(M>>1);
            else res=N*(M>>1);
         else res=(N>>1)*M;
      }
      printf("%d knights may be placed on a %d row %d column board.\n",res,N,M);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
