/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  202  C++  "Math, Cycle, Division Algorithm" */
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

map<int,int> rem;
int main(int argc, char *argv[]) {
   int m, n, a, b, lo, hi, tot, x;
   string s;
   while(scanf("%d%d",&a,&b) == 2) {
      rem.clear();
      s = "";
      m = a; n = b;
      lo = hi = -1;
      x = a/b;
      a -= ((a/b) * b);
      rem[a] = 0;
      for(int i = 1; i <= 2 * b; ++i) {
         if(a < b) a*=10;
         int d = a/b;
         a -= (d * b);    
         s += tostr(d);
         if(rem.count(a) == 0) {
            rem[a] = i;
         } else {
            lo = rem[a], hi = i;
            break;
         }
      }
      string cycle = s.substr(lo,hi-lo);
      cycle = sz(cycle) > 50 ? cycle.substr(0, 50) + "...": cycle;
      string dec = s.substr(0,lo) + "(" + cycle + ")";
      tot = hi - lo;
      printf("%d/%d = %d.%s\n",m,n,x,dec.c_str());
      printf("   %d = number of digits in repeating cycle\n\n",tot);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

