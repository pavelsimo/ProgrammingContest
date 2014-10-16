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

const int MAXN = 10000000;
bool seen[MAXN];

typedef long long llong;

llong count(int A, int B) {
   llong res = 0;
   memset(seen, false, sizeof(seen));
   for(int i = A; i <= B; ++i) {
      if(seen[i]) continue;
      seen[i] = true;
      string n = tostr(i);
      llong cnt = 1;
      for(int j = 1; j < sz(n); ++j) {
         string m = n.substr(j) + n.substr(0,j);
         int m1 = atoi(m.c_str());
         if(!seen[m1] && m1 >= A && m1 <= B) {
            cnt++;
            seen[m1] = true;
         }
      }
      res+=cnt*(cnt-1LL)/2LL;
   }
   return res;
}

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(0);
   int TC, lo, hi; 
   cin >> TC;
   for(int tc = 1; tc <= TC; ++tc) {
      cin >> lo >> hi;
      printf("Case #%d: %lld\n",tc, count(lo,hi));
   }
   return 0;
}

