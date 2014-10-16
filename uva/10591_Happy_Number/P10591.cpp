/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10591  C++  "Math, Cycle, Happy Numbers" */
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

bool is_happy(int n) {
   set<int> seen;
   int X = n;
   seen.insert(X);
   while(X != 1) {
      int sum = 0;
      while(X > 0) {
         int d = (X%10);
         sum += d*d;
         X/=10;
      }
      X = sum;
      if(seen.count(X) != 0) return false;
      seen.insert(X);
   }
   return true;
}

int main(int argc, char *argv[]) {
   int TC, n;
   scanf("%d",&TC);
   for(int tc = 1; tc <= TC; ++tc) {
      scanf("%d",&n);
      printf("Case #%d: %d is %s.\n", tc, n, is_happy(n) ? "a Happy number": "an Unhappy number");
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

