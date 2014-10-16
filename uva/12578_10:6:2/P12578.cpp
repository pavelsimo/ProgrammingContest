/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12578  C++  "Math, Geometry" */
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

const double PI = acos(-1);

int main(int argc, char *argv[]) {
   int TC;
   double l, w, r, ca, sa;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%lf",&l);
      w = (l / 10.0) * 6.0;
      r =  l / 5.0;
      ca = PI * r * r;
      sa = (l * w) - ca;
      printf("%.2lf %.2lf\n",ca,sa);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
