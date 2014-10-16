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

llong a, n, res = 0LL;
llong X[20000000];

void preproccess() {
   for(int i = 1; i <= a + n; ++i) X[i] = 1;
   for(llong x = 2; x*x <= a + n; ++x) {
      for(llong j = x*x; j <= a + n; j+=x*x)
         X[j] = x;
   }
}

int main(int argc, char *argv[]) { 
   cin >> a >> n;
   preproccess();
   for(llong i = a; i < a + n; ++i) {
      llong x = X[i];
      res+=i/(x*x);
   }
   cout << res << endl;
   return 0;
}

