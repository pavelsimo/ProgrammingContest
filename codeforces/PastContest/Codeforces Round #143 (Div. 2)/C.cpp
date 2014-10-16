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

llong A[100002], n, k;
llong freq = 0;

bool check(llong x) {
   llong op = 0LL;
   llong cnt = 0;
   for(int i = 0; i < n; ++i) {
      if(x >= A[i])
         op += x - A[i], ++cnt;
   }
   if(op < k) {
      if(cnt > freq) {
         freq = cnt;
         return true;
      }
   }
   return false;
}

llong binary_search() {
   llong lo = 0;
   llong hi = 10000000000000000LL;
   while(lo < hi) {
      DEBUG(freq);
      llong mid = lo + (hi - lo)/2LL;
      if(check(mid))
         lo = mid + 1;
      else
         hi = mid;
   }
   return lo;
}

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> n >> k;
   for(int i = 0; i < n; ++i)
      cin >> A[i];
   
   cout << binary_search() << endl;

   return 0;
}

