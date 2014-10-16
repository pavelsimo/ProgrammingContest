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
   ios_base::sync_with_stdio(false);
   int TC, d;
   string s;
   cin >> TC;
   for(int tc = 1; tc <= TC; ++tc) {
      cin >> s >> d;
      string res = s;
      for(int i = 0; i < sz(s); ++i) {
         if(d > 0 && res[i] == '1') {
            res[i] = '0';
            --d;
         }
      }
      for(int i = sz(s) - 1; i >= 0; --i) {
         if(d > 0 && res[i] == s[i]) {
            int digit = res[i] - '0';
            res[i] = '0' + (1 - digit);
            --d;
         }
      }
      cout << "Case #" << tc << ": " << res << endl;
   }
   return 0;
}

