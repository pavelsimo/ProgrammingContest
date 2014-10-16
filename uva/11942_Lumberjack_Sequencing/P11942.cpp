/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11942  C++  "Ad Hoc" */
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

const int MAXN = 10;

int main(int argc, char *argv[]) {
   int TC, a[MAXN];
   scanf("%d",&TC);
   bool inc, dec;
   puts("Lumberjacks:");
   while(TC-- > 0) {
      for(int i = 0; i < MAXN; ++i)
         scanf("%d",&a[i]);
      inc = dec = true;
      for(int i = 0; i < MAXN-1; ++i) {
         if(a[i] < a[i+1]) dec = false;
         if(a[i] > a[i+1]) inc = false;
      }
      if(inc || dec) puts("Ordered");
      else puts("Unordered");
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
