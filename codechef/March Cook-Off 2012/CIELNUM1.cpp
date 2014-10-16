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
#include <regex.h>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

typedef long long llong;

vector<llong> res;
llong MAXN = 1LL << 37;

bool is_ceil(llong n) {
   int c3 = 0, c5 = 0, c8 = 0;
   if(n == 0) return false;
   while(n > 0) {
      int d = n % 10;
      if(d == 3) c3++;
      else if(d == 5) c5++;
      else if(d == 8) c8++;
      n/=10;
   }
   return c8 >= c5 && c5 >= c3;
}

void rec(llong n) {
   if(n > MAXN) {
      return;
   } else {
      if(is_ceil(n)) res.push_back(n);
      rec(n*10 + 3);
      rec(n*10 + 5);
      rec(n*10 + 8);
   }
}

int main(int argc, char *argv[]) {
   rec(0);
   sort(all(res));
   for(int i = 0; i < 50000; ++i)
      printf("%lld\n",res[i]);
   return 0;
}
