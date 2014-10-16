/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12602  C++  "Ad Hoc" */
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


typedef unsigned long long ullong;

int main(int argc, char *argv[]) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int TC;
   string s;
   cin >> TC;
   while(TC-- > 0) {
      cin >> s;
      int a = (s[0]-'A') * 26 * 26 + (s[1]-'A') * 26 + (s[2]-'A');
      int b = (s[4]-'0') * 10 * 10 * 10 + (s[5]-'0') * 10 * 10 + (s[6]-'0') * 10 + (s[7]-'0');
      cout << (abs(a - b) <= 100 ? "nice": "not nice") << endl;
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

