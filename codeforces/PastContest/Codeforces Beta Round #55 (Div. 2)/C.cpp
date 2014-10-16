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

set<char> L;

int main(int argc, char *argv[]) {
   string s;
   int k, N;
   cin >> k >> s;
   N = sz(s);
   for(int i = 0; i < sz(s); ++i) {
      if(s[i] == '?') continue;
      L.insert(s[i]);
   }
   int lo = (N - 1) / 2, hi = N / 2;
   while(lo >= 0 && hi < sz(s)) {
      if(s[lo] == '?' && s[hi] == '?') {
         bool found = false;
         for(char ch = 'a' + k - 1; ch >= 'a'; --ch) {
            if(L.count(ch) == 0) {
               L.insert(ch);
               s[lo] = s[hi] = ch;
               found = true;
               break;
            }
         }  
         if(!found) s[lo] = s[hi] = 'a';
      } else if(s[lo] == '?' && isalpha(s[hi])) {
         s[lo] = s[hi];
      } else if(s[hi] == '?' && isalpha(s[lo])) {
         s[hi] = s[lo];
      } else if(s[lo] != s[hi]) {
         cout << "IMPOSSIBLE" << endl;
         return 0;
      }
      lo--;
      hi++;
   }
   if(sz(L) < k) {
      cout << "IMPOSSIBLE" << endl;
      return 0;
   }
   cout << s << endl;
   return 0;
}
