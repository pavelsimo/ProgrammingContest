/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12542  C++  "Prime Numbers, Strings" */
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

vector<int> primes;

#define MAXP 100002
bool sieve[MAXP+1];
#define NOTPRIME(b) (sieve[(b)])

void sieve_erastothenes() {
   register unsigned int p;
   
   primes.clear();
   primes.reserve((int) ceil((MAXP+1)/log(MAXP+1)*(1 + 1.2762/log(MAXP+1))));
   
   sieve[0] = sieve[1] = true;
   for (p = 2; ; ++p) {
      ullong p2 = ((ullong) p) * ((ullong) p);
      if (p2 > MAXP) break;
      if (NOTPRIME(p)) continue;
      primes.push_back(p);
      for (ullong k = p2; k <= MAXP; k += p)
         sieve[k] = true;
   }
   for (; p <= MAXP; ++p) {
      if (NOTPRIME(p)) continue;
      primes.push_back(p);
   }
}

int main(int argc, char *argv[]) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   sieve_erastothenes();
   string s;
   int res;
   while(cin >> s) {
      if(s == "0") break;
      res = 0;
      for(int i = 0; i < sz(s); ++i) {
         int x = 0;
         for(int j = 0; j < 5; ++j) {
            if(i + j >= sz(s)) break;
            x = x*10 + (s[i + j] - '0');
            if(binary_search(all(primes), x))
               res = max(res, x);
         }
      }
      cout << res << endl;
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

