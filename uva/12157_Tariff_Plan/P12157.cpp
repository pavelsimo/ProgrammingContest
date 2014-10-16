/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12157  C++  "Ad Hoc, Math" */
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


int main(int argc, char *argv[]) {
   int TC, n, mile, juice, time;
   scanf("%d",&TC);
   for(int tc = 1; tc <= TC; ++tc) {
      scanf("%d",&n);
      mile = juice = 0;
      for(int i = 0; i < n; ++i) {
         scanf("%d",&time);
         mile = mile + 10 * (1 + time / 30);
         juice = juice + 15 * (1 + time / 60);
      }
      printf("Case %d: ",tc);
      if(mile == juice) printf("Mile Juice %d\n",mile);
      else if(mile < juice) printf("Mile %d\n",mile);
      else printf("Juice %d\n",juice);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

