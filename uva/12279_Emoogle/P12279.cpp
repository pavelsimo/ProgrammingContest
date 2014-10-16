/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12279  C++  "Ad Hoc" */
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
   int N, a, b, c;
   for(int tc = 1; 1 == scanf("%d",&N); ++tc) {
      if(!N) break;
      a = b = 0;
      for(int i = 0; i < N; ++i) {
         scanf("%d",&c);
         if(c > 0) a++;
         else b++;
      }
      printf("Case %d: %d\n",tc,a-b);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
