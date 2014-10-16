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

llong n, size;

set<llong> S;

llong to_num(llong a, llong x, llong y, llong s) {
   llong res = 0LL;
   for(llong i = 0; i < s; ++i)
      res = res * 10LL + ((a & (1LL << i)) ? x: y);
   return res;
}

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> n;
   size = tostr(n).size();
   llong res = 0LL;
   for(int k = 0; k <= size; ++k) {
      for(int i = 0; i < (1 << k); ++i) {
         for(int x = 0; x <= 9; ++x) {
            for(int y = 0; y <= 9; ++y) {
               llong t1 = to_num(i, x, y, k);
               if(t1 <= n && S.count(t1) == 0) {
                  S.insert(t1);
                  res++;
               }
            }
         }
      }            
   }
   cout << res - 1 << endl;
   return 0;
}

