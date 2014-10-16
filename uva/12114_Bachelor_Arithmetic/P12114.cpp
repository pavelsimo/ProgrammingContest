/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12114  C++  "Ad Hoc, Math" */
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
   llong B, S;
   for(int tc = 1; 2 == scanf("%lld%lld",&B,&S); ++tc) {
      if(!B && !S) break;
      printf("Case %d: ",tc);
      if(B - 1 == 0) puts(":-\\");
      else if(S >= B) puts(":-|");
      else {
         if(S*(B-1) > B*(S-1)) puts(":-(");
         else if(S*(B-1) < B*(S-1)) puts(":-)");
         else puts(":-|");
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
