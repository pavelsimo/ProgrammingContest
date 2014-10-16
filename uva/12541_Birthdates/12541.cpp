/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12541  C++  "Ad Hoc" */
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

pair<string, string> P[202];

int main(int argc, char *argv[]) {
   int n;
   string name, d, m, y;
   while(cin >> n) {
      for(int i = 0; i < n; ++i) {
         cin >> P[i].second >> d >> m >> y;
         if(d.size() == 1) d = "0" + d;
         if(m.size() == 1) m = "0" + m;
         P[i].first = y + m + d;
      }
      sort(P, P + n);
      cout << P[n - 1].second << endl;
      cout << P[0].second << endl;
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

