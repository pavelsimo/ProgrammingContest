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
#include <regex.h>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }


int main(int argc, char *argv[]) {
   string s;
   int TC, K, n, is_valid;
   cin >> TC;
   while(TC-- > 0) {
      cin >> K >> s;
      n = sz(s);
      is_valid = 1;
      for(int i = 0; i < n; ++i) {
         int l = (n + i - 1) % n;
         int r = (i + 1) % n;
         if(s[i] == '?') {
            int k;
            for(k = 0; k < K; ++k) {
               int ok = 0;
               char d = (char)('0'+ k);
               if(s[l] == '?' || s[l] != d) ok|=1;
               if(s[r] == '?' || s[r] != d) ok|=2;
               if(ok == 3) {
                  s[i] = d;
                  break;
               }
            }
            if(k == K) is_valid = 0;
         } else {
            int ok = 0;
            if(s[l] == '?' || s[l] != s[i]) ok|=1;
            if(s[r] == '?' || s[r] != s[i]) ok|=2;            
            if(ok != 3) is_valid = 0;
         }
      }
      DEBUG(s);
      puts((is_valid || n == 1) ? s.c_str(): "NO");
   }
   return 0;
}
