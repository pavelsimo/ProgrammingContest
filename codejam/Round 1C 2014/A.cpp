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
   cin.tie(NULL);
   int TC;
   string S;
   cin >> TC;
   for(int tc = 1; tc <= TC; ++tc) {
      bool dem = false;
      llong P = 0LL, Q = 0LL, cnt = 0;
      cin >> S;
      for(int i = 0; i < sz(S); ++i) {
         if(S[i] == '/') {
            dem = true;
            continue;
         }
         if(dem) {
            Q = Q*10LL + (S[i]-'0');
         } else {
            P = P*10LL + (S[i]-'0');
         }
      }
      while(Q > P && Q % 2LL == 0) {
         cnt++;
         Q/=2LL;
      }
      cout << "Case #" << tc << ": "; 
      if(!cnt) cout << "impossible";
      else cout << cnt;
      cout << endl;
   }
   return 0;
}
