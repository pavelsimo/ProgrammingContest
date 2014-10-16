/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ HUBULLU C++ "Ad Hoc, Game Theory" */
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

string player[] = {"Airborne","Pagfloyd"};

int main(int argc, char *argv[]) {
   int TC, p;
   llong N;
   cin >> TC;
   while(TC-- > 0) {
      cin >> N >> p;
      printf("%s wins.\n",player[p].c_str());
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

