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

const int MAXN = 2000002; 

llong d[MAXN];
const llong MOD = 1073741824;

void sieve() {
   for(int i = 0; i < MAXN; ++i)
      d[i] = 1LL;
   d[1] = 1; d[0] = 0;
   for(int i = 2; i < MAXN; ++i) {
      for(int j = i; j < MAXN; j += i)
         d[j]++;
   }
}

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   sieve();
   llong sum = 0LL;
   int a, b, c;
   cin >> a >> b >> c;
   for(int i = 1; i <= a; ++i) {
      for(int j = 1; j <= b; ++j) {
         for(int k = 1; k <= c; ++k) {
            sum = (sum + d[i * j * k]) % MOD;
         }
      }
   }
   cout << sum << endl;
   return 0;
}

