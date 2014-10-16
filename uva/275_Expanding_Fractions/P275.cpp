/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  275  C++  "Math, Cycle, Division Algorithm" */
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
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }


int main(int argc, char *argv[]) {
   int a, b, lo, hi;
   string ans;
   bool terminates;
   map<int,int> rem;
   for(int tc = 0; scanf("%d%d",&a,&b) == 2; ++tc) {
      if(!a && !b) break;
      rem.clear();
      terminates = false;
      ans = "";
      lo = hi = -1;
      rem[a] = 0;
      for(int i = 1; i <= 2 * b; ++i) {
         if(a < b) a*=10;
         int d = a/b;
         a -= (d * b);    
         ans += tostr(d);
         if(lo == -1 && hi == -1 && rem.count(a) != 0) 
            lo = rem[a], hi = i;
         else 
            rem[a] = i;   
         if(a == 0) {
            lo = 0, hi = sz(ans), terminates = true; 
            break;
         }
      }
      printf(".");
      for(int i = 0, j = 49; i < hi; ++i, --j) {
         if(j == 0) printf("\n");
         printf("%c",ans[i]);
         if(j == 0) j = 50;
      }
      printf("\n");
      if(terminates) {
         printf("This expansion terminates.\n");
      } else {
         printf("The last %d digits repeat forever.\n",hi - lo);
      }
      printf("\n");
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

