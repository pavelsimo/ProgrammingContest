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

bool D[10];

bool check(llong x) {
   while(x > 0) {
      if(D[x % 10]) 
         return true;
      x/=10LL;
   }
   return false;
}

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   llong x, t, res = 0;
   cin >> x;
   t = x; 
   while(t > 0) {
      D[t % 10] = true;
      t/=10LL;
   }
   for(llong d = 1LL; d * d <= x; ++d) {
      if(x % d == 0) {
         llong div1 = d;
         llong div2 = x/d;
         if(check(div1)) res++;
         if(div1 != div2 && check(div2)) res++;
      }
   }
   cout << res << endl;
   return 0;
}

