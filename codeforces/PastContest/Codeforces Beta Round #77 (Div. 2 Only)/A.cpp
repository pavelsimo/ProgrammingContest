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

typedef long long llong;

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   int c0, c1;
   string s;
   cin >> s;
   c0 = c1 = 0;
   for(int i = 0; i < sz(s); ++i) {
      if(s[i] - '0') c1++, c0 = 0;
      else c0++, c1 = 0;
      if(c0 >= 7 || c1 >= 7) {
         cout << "YES" << endl;
         return 0;
      }
   }
   cout << "NO" << endl;
   return 0;
}

