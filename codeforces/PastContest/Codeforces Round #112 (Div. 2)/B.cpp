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

bool check(llong cur, llong v, llong k) {
   llong kp = 1LL;
   while(v/kp > 0) {
      cur-=v/kp;
      kp*=k;
   }
   return cur > 0;
}

llong binary_search(llong n, llong k) {
   llong lo = 1LL;
   llong hi = n;
   while(lo < hi) {
      llong mid = lo + (hi - lo)/ 2LL;
      if(check(n, mid, k))
         lo = mid + 1;
      else
         hi = mid;
   }
   return lo;
}


int main(int argc, char *argv[]) {
   llong n, k;
   cin >> n >> k;
   cout << binary_search(n, k) << endl;   
   return 0;
}

