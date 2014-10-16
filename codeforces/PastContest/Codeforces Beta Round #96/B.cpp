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

const llong MOD = 1000003LL;

int main(int argc, char *argv[]) {
   map<char,string> m;
   m['>']="1000"; m['<']="1001";
   m['+']="1010"; m['-']="1011";
   m['.']="1100"; m[',']="1101";
   m['[']="1110"; m[']']="1111";
   llong pow2 = 1, res = 0;
   string buf, s = "";
   cin >> buf;
   for(int i = 0; i < sz(buf); ++i)
      s+=m[buf[i]];
   for(int j = sz(s)-1; j >= 0; --j) {
      res  = (res+pow2*(s[j]-'0'))%MOD;
      pow2 = (pow2*2LL)%MOD;
   }
   cout << res << endl;
   return 0;
}

