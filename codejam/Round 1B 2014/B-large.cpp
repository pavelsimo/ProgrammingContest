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


llong get_highest_bit(llong num) {
    if (!num)
    	return 0;
    llong ret = 1;
    int count = 0;
    while (num >>= 1) {
    	ret <<= 1;
      count++;
    }
    return count;
}

llong calc(llong X) {
   llong N = get_highest_bit(X);
   llong res = 1;
   DEBUG(X);
   for(int i = 0; i <= N; ++i)
      res *= 2LL;
   DEBUG(res);
   return res;
}

int main(int argc, char *argv[]) { 
  int TC;
  cin >> TC;
  for(int tc = 1; tc <= TC; ++tc) {
    llong A, B, K;
    cin >> A >> B >> K;
    llong res = a_high * b_high;
    //cout << a_high << " " << b_high << " " << k_high << endl;
    printf("Case #%d: %lld\n", tc, res);
  }
  return 0;
}
