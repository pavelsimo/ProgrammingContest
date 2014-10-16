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

typedef unsigned long long ullong;

#define MAXP 2000000
bool sieve[MAXP+1];
#define NOTPRIME(b) (sieve[(b)])

int DP[2000002];

void sieve_erastothenes() {
   register unsigned int p;
   sieve[0] = sieve[1] = true;
   for (p = 2; ; ++p) {
      ullong p2 = ((ullong) p) * ((ullong) p);
      if (p2 > MAXP) break;
      if (NOTPRIME(p)) continue;
      for (ullong k = p2; k <= MAXP; k += p)
         sieve[k] = true;
   }
}

int a, b, k;

int check(int l) {
   for(int x = a; x <= b - l + 1; ++x)
      if(DP[x + l - 1] - DP[x - 1] < k) 
         return false;
   return true;
}

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   sieve_erastothenes();
   DP[1] = 0;
   for (int i = 2; i <= MAXP; ++i) {
      DP[i] = DP[i - 1];
      if (NOTPRIME(i)) continue;
      DP[i]++;
   }
   cin >> a >> b >> k;
   int lo = 1;
   int hi = b - a + 1;
   while(lo < hi) {
      int l = lo + (hi - lo)/ 2;
      if(check(l))
         hi = l;
      else
         lo = l + 1;
   }
   if(!check(lo)) {
      cout << -1 << endl;
      return 0;
   }
   cout << lo << endl;
   return 0;
}

