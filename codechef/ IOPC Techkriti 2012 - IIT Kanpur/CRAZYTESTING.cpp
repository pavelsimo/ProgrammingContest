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
map<char,string> m_str;
const llong MOD = 100000007LL;

int main(int argc, char *argv[]) {
   m_str['a'] = "2"; m_str['b'] = "22"; m_str['c'] = "222";
   m_str['d'] = "3"; m_str['e'] = "33"; m_str['f'] = "333";
   m_str['g'] = "4"; m_str['h'] = "44"; m_str['i'] = "444";
   m_str['j'] = "5"; m_str['k'] = "55"; m_str['l'] = "555";
   m_str['m'] = "6"; m_str['n'] = "66"; m_str['o'] = "666";
   m_str['p'] = "7"; m_str['q'] = "77"; m_str['r'] = "777"; m_str['s'] = "7777";
   m_str['t'] = "8"; m_str['u'] = "88"; m_str['v'] = "888";
   m_str['w'] = "9"; m_str['x'] = "99"; m_str['y'] = "999"; m_str['z'] = "9999";
   int TC;
   llong res;
   char prev;
   string a, s;
   cin >> TC;
   while(TC-- > 0) {
      s = "";
      cin >> a;   
      for(int i = 0; i < sz(a); ++i)
         s+=m_str[a[i]];
      res = 1LL;
      prev = s[0];
      for(int i = 1; i < sz(s); ++i) {
         while(prev == s[i]) {
            res = (res * 2LL) % MOD;
            prev = s[i];  
            ++i;
         }
         prev = s[i];
      }
      cout << res << endl;
   }
   return 0;
}
